
#include "LibApp.h"

namespace sdds 
{

	// Constructor initializes the menus 
	LibApp::LibApp()  : m_mainMenu("Seneca Library Application") , m_exitMenu("Changes have been made to the data, what would you like to do?")
	{
		m_changed = false;

		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";

		m_exitMenu << "Save changes and exit" ;
		m_exitMenu << "Cancel and go back to the main menu" ;

		load();
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
					if (exitRunReturn==1)
					{
						save();
						finalExitReturn = true;
						
					}

					if (exitRunReturn == 2)
					{
						choice = exitRunReturn;	
					}

					else if(exitRunReturn==0)
					{
						finalExitReturn = confirm("This will discard all the changes are you sure?") ;

					}
				}

				else if(!m_changed)
				{
					finalExitReturn = true; 
				}

			}

			std::cout << std::endl;
			
		} while ( !finalExitReturn); 

		std :: cout << "-------------------------------------------" << std::endl;
		std::cout << "Thanks for using Seneca Library Application" << std::endl;

	}

	void LibApp::newPublication()
	{
		bool confirmReturn = false;
		std::cout << "Adding new publication to library" << std::endl;
		confirmReturn = confirm("Add this publication to library?");
		if (confirmReturn)
		{
			m_changed = true;
			std::cout << "Publication added" << std::endl;

		}
	}

	void LibApp::removePublication()
	{
		bool confirmReturn = false;
		std::cout << "Removing publication from library" << std::endl;
		search();
		confirmReturn = confirm("Remove this publication from the library?");
		if (confirmReturn)
		{
			m_changed = true;
			std::cout << "Publication removed" << std::endl ;
		}

	}

	void LibApp::checkOutPub()
	{
		bool confirmReturn = false;
		search();
		confirmReturn = confirm("Check out publication?");
		if (confirmReturn)
		{
			m_changed = true;
			std::cout << "Publication checked out" << std::endl ;
		}
	}


	bool LibApp::confirm(const char* message) 
	{

		bool runReturned = false;
		bool returnValue= false;
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
	}

	void LibApp::save()
	{
		std::cout << "Saving Data" << std::endl;
	}

	void LibApp::search()
	{
		std::cout << "Searching for publication" << std::endl;
	}

	void LibApp::returnPub()
	{
		search();
		std::cout << "Returning publication" << std::endl;
		std::cout << "Publication returned" << std::endl  ;
		

		m_changed = true;


	}















}
