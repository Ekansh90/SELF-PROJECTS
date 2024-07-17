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


#ifndef _SDDS_STREAMABLE_H
#define  _SDDS_STREAMABLE_H

#include <iostream>

namespace sdds
{
	// interface
	class Streamable 
	{
	public :
		virtual std::ostream& write(std::ostream& os)const = 0;
		virtual std::istream& read(std::istream& is) = 0;

		// overriding function determines if incoming ios object is a console IO object or not
		virtual bool conIO(const std::ios &ios) const;

		// Identifies whether STREAMABLE object is in safe empty state or not .
		virtual operator bool()const = 0 ;

		virtual ~Streamable();	
	};

	// insertion operator overload
		// writes streamble object to ostream if it is in valid state
	std::ostream& operator <<(std::ostream& os, const Streamable& st);

	// extraction opeator overload
	std::istream& operator >>(std::istream& is, Streamable& st);

}
#endif // !_SDDS_STREAMABLE_H
