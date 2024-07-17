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

		//2.write
		std::ostream& write(std::ostream& os)const;

		//3.read
		std::istream& read(std::istream& is);

		//4.set
		void set(int member_id);


		//5.bool operator
		operator bool()const;

		// rule of three
		Book(const Book& rhs);
		Book& operator =(const Book& rhs);
		~Book();
	};

	// insertion operator overload
	// writes a Book object to ostream
	std::ostream& operator <<(std::ostream& os, const Book& bk);

	// extraction operator overload
	// reads a Book object from ostream
	std::ostream& operator >>(std::ostream& os, Book& bk);
}

#endif // !_SDDS_BOOK_H

