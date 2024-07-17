/*/////////////////////////////////////////////////////////////////////////
						 Milestone - 4
Full Name  : Ekansh
Email      : ekansh@myseneca.ca
Student ID#: 167454214
Section    : OOP 244 -NAA

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#ifndef _SDDS_BOOK_H
#define _SDDS_BOOK_H

#define MAX_AUTHOR_NAME 256

#include <iostream>
#include "Publication.h"
#include "Utils.h"

namespace sdds
{
	class Book : public Publication
	{
	private:
		char* m_author;

	public :
		Book();

		//1.Returns the character 'B' to identify this object as a "Book-object"
		char type()const;

		/// <summary>
		/// Displays the Book Details ( Publication content ) and the author details on ostream
		/// </summary>
		/// <param name="os"></param>
		/// <returns></returns>
		std::ostream& write(std::ostream& os)const;

		/// <summary>
		/// Reads input for publication details and then author details
		/// </summary>
		/// <param name="is">Incoming ostream object</param>
		/// <returns></returns>
		std::istream& read(std::istream& is);

		/// <summary>
		/// Sets member Id using base class set function
		/// and resets the date
		/// </summary>
		/// <param name="member_id">Incoming arguement is assigned to membership attribute</param>
		void set(int member_id);


		/// <summary>
		/// Overloaded bool operator :
		/// - Returns true if author is not null
		///   and base class bool operator returns true
		/// </summary>
		operator bool()const;

		/// <summary>
		/// Copy constructor
		/// </summary>
		/// <param name="rhs"></param>
		Book(const Book& rhs);

		/// <summary>
		/// Copy assignment operator
		/// </summary>
		/// <param name="rhs"></param>
		/// <returns></returns>
		Book& operator =(const Book& rhs);
		~Book();
	};

	// insertion operator overload
	// calls the write method
	std::ostream& operator <<(std::ostream& os, const Book& bk);

	// extraction operator overload
	// Has not been used yet in the tester , but should call the read method to take input for istream object
	std::istream& operator >>(std::istream& is, Book& bk);
}

#endif // !_SDDS_BOOK_H

