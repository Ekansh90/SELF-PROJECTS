/*/////////////////////////////////////////////////////////////////////////
						 Milestone - 3
Full Name  : Ekansh
Email      : ekansh@myseneca.ca
Student ID#: 167454214
Section    : OOP 244 -NAA

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#ifndef _SDDS_PUBLICATION_H
#define _SDDS_PUBLICATION_H

#define _CRT_SECURE_NO_WARNINGS
#define MAX_TITLE_WIDTH 255
#include <iostream>
#include <cstring>
#include <string>

#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace sdds
{
	class Publication : public Streamable // streamable needs a concrete / derived class to provide implementation for pure virtual function
	{
		// Holds title of publication
		char* m_title;

		// Holds the location of publication in library
		char m_shelfId[5];

		int m_membership;

		// This serial number is used internally to uniquely identify each publication in the system.
		int m_libRef;

		// used to store when the book was borrowed
		Date m_date;


	public:
		Publication();

		//////////// MODIFIERS ///////////////
		

		virtual void set(int member_id);

		// Sets the **libRef** attribute value
		void setRef(int value);

		// Sets the date to the current date of the system.
		void resetDate();

		//////////// QUERIES  ///////////////

		//Returns the character 'P' to identify this object as a "Publication object"
		virtual char type()const;

		//Returns true is the publication is checkout (membership is non-zero)
		bool onLoan()const;

		//Returns the date attribute
		Date checkoutDate()const;

		//Returns true if the argument title appears anywhere in the title of the publication
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		bool operator==(const char* title)const;
		
		//Returns the m_title .
		operator const char* ()const;

		//Returns the libRef . 
		int getRef()const;


		// implementations for pure virtuals 

		std::ostream& write(std::ostream& os)const ;
		std::istream& read(std::istream& is) ;

		operator bool() const;

		/*
		IMPLMENTING RULE OF THREE -
		If a we have to provide extra implementation for any one of the three ( destructor , copy constructor , copy assignmnent operator ).
		Then we should implement all three of them .
		*/


		Publication(const Publication& rhs);


		Publication& operator=(const Publication& rhs);


		~Publication();

	};
	
}

#endif // !_SDDS_PUBLICATION_H
