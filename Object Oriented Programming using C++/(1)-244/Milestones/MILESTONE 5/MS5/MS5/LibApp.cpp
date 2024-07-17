
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include "LibApp.h"

namespace sdds
{
	///////////////////////////////////////////////////
	// HELPERS
	void fcopy(const char* dest, const char* source) {
		ifstream fin(source);
		ofstream fout(dest);
		char ch;
		while (fin.get(ch)) fout << ch;
	}

	Publication readPublication(istream& istr) {
		Publication P;
		istr >> P;
		return P;
	}
	Publication getNextRec(ifstream& ifstr) {
		Publication P;
		ifstr >> P;
		ifstr.ignore(1000, '\n');
		return P;
	}
	///////////////////////////////////////////////////

	// Constructor initializes the menus 
	LibApp::LibApp(const char* fileName) : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_pubType("Choose the type of publication:")
	{
		m_changed = false;

		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";

		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";

		m_pubType << "Book";
		m_pubType << "Publication";

		if (fileName != nullptr)
		{
			strcpy(m_fileName, fileName);
		}

		load();
	}

	///////////////////////////////////////////////////

	bool LibApp::confirm(const char* message)
	{

		bool runReturned = false;
		bool returnValue = false;
		Menu tmp(message);

		tmp << "Yes";
		runReturned = tmp.run();
		if (runReturned)
		{
			returnValue = true;
		}
		return returnValue;
	}


	void LibApp::load()
	{
		std::cout << "Loading Data" << std::endl;
		ifstream filein(m_fileName);

		char type{};
		while (filein >> type)
		{
			filein.ignore();
			if (type == 'P')
			{
				PPA[NOLP] = new Publication;
				filein >> *PPA[NOLP];
			}
			else if (type == 'B')
			{
				PPA[NOLP] = new Book;
				filein >> *PPA[NOLP];
			}
			NOLP++;
		}
		LLRN = PPA[NOLP - 1]->getRef();
	}

	void LibApp::save()
	{
		std::cout << "Saving Data" << std::endl;
		std::ofstream output(m_fileName);

		if (output)
		{
			// connection made succesfully
			for (int i = 0; i < NOLP; i++)
			{
				if ((PPA[i]->getRef()) != 0)
				{
					PPA[i]->write(output);
					output << std::endl;
				}

				else
				{
					continue;
				}
			}
		}
	}


	void LibApp::newPublication()
	{
		bool confirmReturn = false;
		bool maxCapacity = false;
		bool quit = false;
		int choice = 0;
		Publication* p = nullptr;

		if (NOLP == SDDS_LIBRARY_CAPACITY) // HOW COME THE FILE STOPS AT 333 , as according to macro its 1500
		{
			std::cout << "Library is at its maximum capacity!" << std::endl;
			maxCapacity = true;

		}

		else if (!maxCapacity)
		{
			std::cout << "Adding new publication to the library" << std::endl;
			choice = m_pubType.run();


			// validation for choice
			if (choice == 1)
			{
				p = new Book;
				std::cin >> *p;
			}
			else if (choice == 2)
			{
				p = new Publication;
				std::cin >> *p;
			}

			else if (choice == 0)
			{
				quit = true;
				std::cout << "Aborted!" << std::endl;
			}
			////////////////////////

			if (!cin.good())
			{
				cin.clear();
				cin.ignore(1, '\n');
				std::cout << "Aborted!" << std::endl;
				quit = true;
				delete p;

			}

			else if (cin.good() && quit == false)
			{
				confirmReturn = confirm("Add this publication to the library?");
				if (confirmReturn && p)
				{
					LLRN++;
					p->setRef(LLRN);
					PPA[NOLP] = p;
					NOLP++;
					m_changed = true;
					std::cout << "Publication added" << std::endl;
				}

				else if ((confirmReturn && !p))
				{
					std::cout << "Failed to add publication!" << std::endl;
					delete p;
				}

				else
				{
					std::cout << "Aborted!" << std::endl;
					quit = true;
					delete p;
				}
			}
		}
	}


	void LibApp::removePublication()
	{
		bool confirmReturn = false;
		std::cout << "Removing publication from the library" << std::endl;
		int pubIdToRemove = search(SEARCH_ALL_PUBLICATIONS); 


		if (pubIdToRemove)
		{
			confirmReturn = confirm("Remove this publication from the library?");
			if (confirmReturn)
			{
				for (int i = 0; i < NOLP; i++)
				{
					if (PPA[i]->getRef() == pubIdToRemove)
					{
						PPA[i]->setRef(0);
						m_changed = true;
						std::cout << "Publication removed" << std::endl;
					}
				}
			}

			else
			{
				std::cout << "Aborted" << std::endl;
			}



		}

	}

	void LibApp::checkOutPub()
	{
		std::cout << "Checkout publication from the library" << std::endl;
		bool confirmReturn = false;
		int pubIdToCheckout = search(SEARCH_AVAILABLE_PUBLICATIONS); // search available publications only , !onLoan

		if (pubIdToCheckout)
		{
			int input;
			confirmReturn = confirm("Check out publication?");
			if (confirmReturn)
			{
				std::cout << "Enter Membership number: ";
				do
				{
					std::cin >> input;
					if (!(input <= 99999 && input > 9999))
					{
						std::cout << "Invalid membership number, try again: ";
						input = 0;
					}

				} while (input > 99999 || input < 9999);

				int i = 0;
				for (i = 0; i < NOLP; i++)
				{
					if (PPA[i]->getRef() == pubIdToCheckout)
					{
						PPA[i]->set(input);
						m_changed = true;
						std::cout << "Publication checked out" << std::endl;
					}
					
				}
			}

			else
			{
				std::cout << "Aborted" << std::endl;
			}
		}
	}

	void LibApp::returnPub()
	{
		std::cout << "Return publication to the library" << std::endl;
		bool confirmReturn = false;
		int pubIdToReturn = search(SEARCH_LOANED_PUBLICATIONS); 

		// Loop iterator
		int i = 0;

		if (pubIdToReturn)
		{
			confirmReturn = confirm("Return Publication?");
			if (confirmReturn)
			{
				Date tempDate;
				Date currDate;
				int daySince{};
				int daysSinceBorrowed{};
				double penalty{ 0.00 };

				for (i = 0; i < NOLP; i++)
				{
					if (PPA[i]->getRef() == pubIdToReturn)
					{
						tempDate = PPA[i]->checkoutDate();
						daySince = currDate - tempDate;
						daysSinceBorrowed = daySince - 15;

						if (daySince > 15)
						{
							penalty = (daySince - 15) * (0.5);

							std::cout << "Please pay $";
							std::cout << std::fixed << std::setprecision(2) << penalty;
							std::cout << " penalty for being " << daysSinceBorrowed << " days late!" << std::endl;
						}

						m_changed = true;
						PPA[i]->set(0);
						std::cout << "Publication returned" << std::endl;

					}

				}
			}
		}
	}

	int LibApp::search(int mode)
	{
		PublicationSelector collection("Select one of the following found matches:");

		// Input for Pub type
		int choice = m_pubType.run();
		std::cin.ignore();

		// Input for title
		std::cout << "Publication Title: ";
		char title[256 + 1]{};
		std::cin.getline(title, '\n');

		int i;
		char type{};

		if (choice == 1)
			type = 'B';

		else if (choice == 2)
			type = 'P';

		// search all - for removePub
		if (mode == 0)
		{
			for (i = 0; i < NOLP; i++)
			{
				if (PPA[i]->type() == type && strstr(*PPA[i], title))
				{
					collection << PPA[i];
				}
			}
		}

		// on loan by members - for returnPub
		else if (mode == 1)
		{
			for (i = 0; i < NOLP; i++)
			{
				if (PPA[i]->type() == type && strstr(*PPA[i], title) && PPA[i]->onLoan())
				{
					collection << PPA[i];
				}
			}
		}

		// not on loan by members - for checkOutPub
		else if (mode == 2)
		{
			for (i = 0; i < NOLP; i++)
			{
				if (PPA[i]->type() == type && strstr(*PPA[i], title) && !(PPA[i]->onLoan()))
				{
					collection << PPA[i];
				}

			}
		}

		int ref = 0;
		if (collection)
		{
			collection.sort();
			ref = collection.run();// displays the publications and asks which to select
			if (ref)
			{
				prnPub(PPA, 100, ref);
			}
			else
			{
				std::cout << "Aborted!" << std::endl;
			}
		}

		else
		{
			std::cout << "No matches found!" << std::endl;
		}

		return ref;

	}


	Publication* LibApp::getPub(int libRef)
	{

		bool libRefFound = false;

		Publication* foundPub = nullptr ;

		for (int i = 0; i < NOLP && libRefFound != true; i++)
		{
			if (PPA[i]->getRef() == libRef)
			{
				libRefFound = true;
				return PPA[i];
				foundPub = PPA[i] ;
			}
		}
		// use a variable for returning
		//return nullptr;
		return foundPub ;




	}

	void LibApp::run()
	{

		int choice = 0;

		int exitRunReturn = 0;
		bool finalExitReturn = false;
		do
		{
			choice = m_mainMenu.run();

			if (choice == 1)
			{
				newPublication();
			}

			else if (choice == 2)
			{
				removePublication();
			}

			else if (choice == 3)
			{
				checkOutPub();
			}

			else if (choice == 4)
			{
				returnPub();
			}

			else if (choice == 0)
			{
				if (m_changed)
				{
					exitRunReturn = m_exitMenu.run();
					if (exitRunReturn == 1)
					{
						save();
						finalExitReturn = true;

					}

					if (exitRunReturn == 2)
					{
						choice = exitRunReturn;
					}

					else if (exitRunReturn == 0)
					{
						finalExitReturn = confirm("This will discard all the changes are you sure?");

					}
				}

				else if (!m_changed)
				{
					finalExitReturn = true;
				}

			}

			std::cout << std::endl;

		} while (!finalExitReturn);

		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "Thanks for using Seneca Library Application" << std::endl;

	}



	LibApp::~LibApp()
	{

		for (int i = 0; i < NOLP; i++)
		{
			delete PPA[i];
		}
	}








}
