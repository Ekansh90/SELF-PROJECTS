/*/////////////////////////////////////////////////////////////////////////
						 Milestone - 1
Full Name  : Ekansh
Email      : ekansh@myseneca.ca
Student ID#: 167454214
Section    : OOP 244 -NAA

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <string>
#include "Menu.h"
using namespace std;

namespace sdds
{
	// Member functions of MenuItem class


	MenuItem::MenuItem() 
	{
		m_content = nullptr;
	}

	MenuItem::MenuItem(const char* name)
	{
		m_content = nullptr;

		// No memory allocated if name is nullptr
		if (name != nullptr)
		{
			m_content = new char[strLen(name) + 1];
			strCpy(m_content, name);
		}

	}

	MenuItem::~MenuItem()
	{
		delete[] m_content;
		m_content = nullptr;
	}

	
	MenuItem :: operator bool()const
	{
		if (strLen(m_content) != 0)
		{
			return true;
		}

		return false;
	}

	
	MenuItem :: operator const char* ()const
	{
		return m_content;
	}

	/*
	// Method for MenuItem class to display item name
	std::ostream& MenuItem:: operator<<(std::ostream ostr)const
	{
		if (m_content != nullptr)
		{
			ostr << m_content;
		}

		return ostr;
	}
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////



	// Member functions of Menu class

	Menu::Menu() 
	{

		m_number = 0;
		for (int i = 0; i < MAX_MENU_ITEMS; i++)
		{
			list[i] = nullptr;
		}
		m_title = nullptr;


	}


	Menu::Menu(const char* title)
	{
		m_number = 0;
		m_title = nullptr;
		m_title = new MenuItem(title);
		for (int i = 0; i < MAX_MENU_ITEMS; i++)
		{
			list[i] = nullptr;
		}
	}

	Menu :: ~Menu()
	{
		for (int i = 0; (unsigned)i < MAX_MENU_ITEMS; i++)
		{
			delete list[i];
			list[i] = nullptr;
		}
		delete m_title; 
		m_title = nullptr;


	}

	// DONE : Displays the content of Menu ( title and list )
	void Menu::displayMenu(std::ostream& ostr)const
	{
		if (m_number != 0)
		{
			if (m_title != nullptr)
			{
				std::cout << m_title->m_content << ":" << std::endl;
			}

			for (int i = 0; (unsigned int)i < m_number; i++)
			{
				ostr << " " << i + 1 << "- " << list[i]->m_content << std::endl;
			}
			std::cout << " 0- Exit" << std::endl;
			std::cout << "> ";
		}
	}

	
	unsigned int Menu::run()
	{
		bool valid = false;
		int itemNum = 0;
		bool quit = false;

		displayMenu(std::cout);

		while (!quit && !valid)
		{

			std::cin >> itemNum;

			if ((itemNum > 0 && (unsigned int)itemNum <= m_number))
			{
				valid = true;

			}

			else if (std::cin.fail())
			{
				// clears the failed state so next input can be took
				std::cin.clear();

				// discard the remaining input buffer
				std::cin.ignore(1000, '\n');

				std::cout << "Invalid Selection, try again: ";

			}

			else if (itemNum == 0 && !cin.fail())
			{
				quit = true;
				valid = true;
			}

			else
			{
				std::cout << "Invalid Selection, try again: ";


			}

		}
		return itemNum;


	}


	unsigned int Menu :: operator~()
	{
		bool valid = false;
		int itemNum = 0;
		bool quit = false;

		displayMenu(std::cout);

		while (!quit && !valid)
		{

			std::cin >> itemNum;

			if ((itemNum > 0 && (unsigned int)itemNum <= m_number))
			{
				valid = true;

			}

			else if (std::cin.fail())
			{
				// clears the failed state so next input can be took
				std::cin.clear();

				// discard the remaining input buffer
				std::cin.ignore(1000, '\n');

				std::cout << "Invalid Selection, try again: ";

			}

			else if (itemNum == 0 && !cin.fail())
			{
				quit = true;
				valid = true;
			}

			else
			{
				std::cout << "Invalid Selection, try again: ";


			}

		}
		return itemNum;


	}


	Menu& Menu :: operator<<(const char* menuitemContent)
	{
		bool empty = false;
		int i = 0;
		for (i = 0; i < MAX_MENU_ITEMS && empty == false; )
		{
			if (list[i] == nullptr)
			{
				empty = true;
			}

			else
			{
				i++;
			}
		}

		if (empty == true)
		{
			// DYNAMICALLY create menuItem using the constructor and stores it in list
			list[i] = new MenuItem(menuitemContent); 
			m_number++;
		}

		return *this;
	}

	Menu :: operator int()const
	{
		return m_number;
	}

	Menu:: operator unsigned int()const
	{
		return m_number;
	}

	Menu ::operator bool()const
	{
		bool isEmpty = false;
		if (m_number != 0)
		{
			isEmpty = true;
		}

		return isEmpty;
	}



	const char* Menu ::operator[](unsigned int index)const
	{
		const char* returnVal = nullptr;
		if (*this)
		{
			// list is a pointer , casting will try to cast an address , dereferencing * and then casting works
			returnVal = (const char*)*list[index % m_number];
		}
		return returnVal;
	}

	void Menu::displayTitle()const
	{
		std::cout << m_title->m_content;
	}

	// overloaded insertion operator to print m_title
		std::ostream& operator <<(std::ostream& ostr, Menu& menuTitle)
	{
		if (menuTitle)
		{
			menuTitle.displayTitle();
		}

		return std::cout;
	}




}