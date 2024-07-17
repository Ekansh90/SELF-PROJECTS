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

#include <iostream>
//#include <cstring>
//#include "cstring.h"
#include "Utils.h"

#ifndef _SDDS_MENU_H
#define _SDDS_MENU_H

#define MAX_MENU_ITEMS 20

namespace sdds
{

	

	// Fully private  MenuItem Class
	class MenuItem
	{
	private:

		// Dynamically C-string  
		char* m_content;

		// Constructors and Destructors

		/// <summary>
		/// Sets MenuItem to safe empty state
		/// </summary>
		MenuItem();

		/// <summary>
		/// Sets MenuItem to safe empty state and assigns m_content to incoming arguement 
		/// </summary>
		/// <param name="name"></param>
		MenuItem(const char* name);


		~MenuItem();

		// Type conversion operators

		/// <summary>
		/// // Bool casting operator : Returns true if char array is empty
		/// </summary>
		operator bool() const;

		/// <summary>
		/// Returns C-string
		/// </summary>
		operator const char* ()const;

		// copy constructor and copy assignment operator prevention 
		MenuItem(const MenuItem&) = delete;
		MenuItem operator = (const MenuItem&) = delete;

		friend class Menu;

		// display content of MenuItem character array
		std::ostream& operator<<(std::ostream ostr)const;

	};

	class Menu
	{
	private:

		MenuItem* m_title;
		MenuItem* list[MAX_MENU_ITEMS];
		unsigned int m_number;

	public:

		Menu();
		Menu(const char*);
		~Menu();

		// display entire menu on ostream 
		void displayMenu(std::ostream& ostr)const;

		/// <summary>
		/// Displays Menu and the items in it and asks for user selection to enter new items .
		/// </summary>
		/// <returns></returns>
		unsigned int run();

		/// <summary>
		///  Displays Menu and the items in it and asks for user selection to enter new items .
		/// </summary>
		/// <returns></returns>
		unsigned int operator ~();

		/// <summary>
		/// Adds a new item to Menu
		/// </summary>
		/// <param name="menuitemConent"></param>
		/// <returns></returns>
		Menu& operator << (const char* menuitemConent);


		// overloaded conversion operators which return number of MenuItems 
		operator int()const;
		operator unsigned int()const;

		//overload bool operator ; true if MENU is not empty
		operator bool()const;

		const char* operator[](unsigned int)const;

		// copy constructor and assignment prevention goes here
		Menu(const Menu&) = delete;
		Menu& operator = (const Menu&) = delete;

		/// <summary>
		/// Displays the title of the menu
		/// </summary>
		void displayTitle()const;

	};

	// overloaded insertion operator to print m_title
	std::ostream& operator <<(std::ostream& ostr, Menu& menuTitle);

}
#endif // !_SDDS_MENU_H
