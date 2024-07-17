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

	// test
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
				
				
				//displayContent(os, m_author, SDDS_AUTHOR_WIDTH);
				os << ' ';
				os << '|';
			}

			else
			{
				os << '\t';
				os << m_author;
			}
		}


		return os;

	}

	// test
	std::istream& Book::read(std::istream& is)
	{
		// local variables
		char ch{}; // character to read from istream character by character
		char tempName[256] = { '\0' }; // temp array to store value for author name
		
		Publication::read(is);

		delete[] m_author;
		m_author = nullptr;
		int i = 0;

		if (conIO(is))
		{
			is.ignore(1, '\n');
			std::cout << "Author: ";

			// was this the correct syntax fpr reading till \n is found
			//is.read(tempName, MAX_AUTHOR_NAME);
			

			while (is.get(ch) && ch!='\n')
			{
				tempName[i] = ch;
				i++;
			}
			
			tempName[i] = '\0';
			
		
		}

		else
		{
			is.ignore(1, '\t');
			//std::getline(is, temp, '\t');
			
			// was this the correct syntax fpr reading till \n is found
			//is.read(tempName, '\n');
			//tempName[is.gcount()] = '\0';
			
			while (is.peek() != '\n' && is.good())
			{
				is.get(ch);
				tempName[i] = ch;
				i++;
				
				
			}
			tempName[i] = '\0';
			
			
			
			
		}

		if (is.good())
		{
			m_author = nullptr;
			m_author = new char[strlen(tempName) + 1];
			strcpy(m_author, tempName);

		}
		return is;
	}

	// test

	/// <summary>
	/// Sets member Id using base class set function
	/// and resets the date
	/// </summary>
	/// <param name="member_id">Incoming arguement is assigned to membership attribute</param>
	void Book::set(int member_id)
	{
		Publication::set(member_id);
		resetDate();
	}

	/*
	* Returns true if author is not null
	* and base class bool operator returns true
	*/
	Book::operator bool() const
	{
		// correct syntax
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
		// TODO: insert return statement here
		bk.write(os);

		return os;
	}

}

