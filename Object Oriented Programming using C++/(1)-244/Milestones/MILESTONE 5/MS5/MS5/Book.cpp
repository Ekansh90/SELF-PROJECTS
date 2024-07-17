#include "Book.h"

namespace sdds
{
	Book::Book()
	{
		m_author = nullptr;
	}

	char Book::type() const
	{
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const
	{
		Publication::write(os);

		if (m_author != nullptr)
		{
			if (conIO(os))
			{
				os << ' ';
				size_t titleLength = strlen(m_author);
				for (size_t i = 0; i < SDDS_AUTHOR_WIDTH; i++)
				{
					if (i < titleLength && m_author[i] != '\0') 
					{
						os << m_author[i];
					}

					else 
					{
						os << ' ';
					}
				}
				
				os << ' ';
				os << '|';
			}

			else
			{
		
				os << '\t';
				os << m_author ;
			}
		}
		return os;
	}

	std::istream& Book::read(std::istream& is)
	{
		Publication::read(is);

		// local variables
		char ch{}; // character to read from istream character by character
		char tempName[256] = { '\0' }; // temp array to store value for author name
		

		delete[] m_author;
		m_author = nullptr;
		int i = 0;

		if (conIO(is))
		{
			is.ignore(1, '\n');
			std::cout << "Author: ";
			while (is.peek() != '\n' && is.good())
			{
				is.get(ch);
				tempName[i] = ch;
				i++;
			}
			
			tempName[i] = '\0';
			
		
		}

		else
		{
			is.ignore(1, '\t');
			while (is.peek() != '\n' && is.good())
			{
				is.get(ch);
				tempName[i] = ch;
				i++;
			}
			tempName[i] = '\0';	
		}

		// Sets up value for author attribute if the istream object 
		// is in valid state and has not failed while reading input
		if (is.good())
		{
			m_author = nullptr;
			m_author = new char[strlen(tempName) + 1];
			strcpy(m_author, tempName);

		}
		return is;
	}

	void Book::set(int member_id)
	{
		Publication::set(member_id);
		resetDate();
	}

	Book::operator bool() const
	{
		bool returnVal = false;
		if (Publication :: operator bool() && m_author != nullptr)
		{
			returnVal = true;
		}
		return returnVal;
	}

	
	Book::Book(const Book& rhs)
	{
		m_author = nullptr;
		if (rhs.m_author != nullptr)
		{
			Publication::operator=(rhs);
			m_author = new char[strlen(rhs.m_author) + 1];
			strcpy(m_author, rhs.m_author);
		}
	}

	Book& Book::operator=(const Book& rhs)
	{
		delete[] m_author;
		m_author = nullptr;
		if (this!=&rhs && rhs.m_author!=nullptr)
		{
			Publication::operator=(rhs);
			m_author = new char[strlen(rhs.m_author) + 1];
			strcpy(m_author, rhs.m_author);
		}
		return *this;
	}

	Book::~Book()
	{
		delete[] m_author;
		m_author = nullptr;
	}

	std::ostream& operator<<(std::ostream& os, const Book& bk)
	{
		bk.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, Book& bk)
	{
		bk.read(is);
		return is;
	}

}

