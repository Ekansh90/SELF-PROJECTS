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


#include "Streamable.h"

namespace sdds
{
	bool Streamable::conIO(const std::ios &ios) const
	{
		bool isConsoleObject = false;
		if (&ios==&std::cin || &ios == &std::cout)
		{
			isConsoleObject = true;
		}

		return isConsoleObject;
	}

	Streamable::~Streamable()
	{
		;
	}

	
	std::ostream& operator<<(std::ostream& os, const Streamable& st)
	{
		st.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& is,Streamable& st)
	{
		st.read(is);
		return is;
		
	}

}
