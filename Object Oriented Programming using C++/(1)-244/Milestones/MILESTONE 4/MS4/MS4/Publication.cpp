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

#include "Publication.h"

namespace sdds
{
	Publication::Publication()
	{
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date = Date();
	}

	/// <summary>
	/// Sets membership to incoming arguement 
	/// </summary>
	/// <param name="member_id">Should be a 5 digit number</param>
	void Publication::set(int member_id)
	{
		if (member_id>=10000 && member_id<=99999)
		{
			m_membership = member_id;
		}
		else
		{
			m_membership = 0;
		}
	}

	/// <summary>
	/// Sets library refrence number 
	/// </summary>
	/// <param name="value">to the incoming arguement</param>
	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	/// <summary>
	/// Resets the date attribute by calling Date constructor which itself sets the date to system date .
	/// </summary>
	void Publication::resetDate()
	{
		m_date = Date(); 
	}

	/////////////////////// QUERIES //////////////////////////

	/// <summary>
	/// Returns publication type .
	/// </summary>
	/// <returns></returns>
	char Publication::type() const
	{
		return 'P';
	}


	/// <summary>
	/// Checks if the publication has already been borrowed by someone .
	/// Returns true if publication has been assigned to existing membership id .
	/// </summary>
	/// <returns></returns>
	bool Publication::onLoan() const
	{
		bool pubUnvailable = false;
		if (m_membership!=0)
		{
			pubUnvailable = true;
		}
		return pubUnvailable;
	}

	/// <summary>
	/// Returns the date attribute .
	/// </summary>
	/// <returns></returns>
	Date Publication::checkoutDate() const
	{
		return m_date;
	}

	/// <summary>
	/// Checks if incoming arguement is a part of title attribute .
	/// </summary>
	/// <param name="title">Returns true if incoming parameter is a substring of m_title</param>
	/// <returns></returns>
	bool Publication::operator==(const char* title) const
	{
		bool substrExists = false;
		char* strstrResult = strstr(m_title,title);
		if (strstrResult!=NULL)
		{
			substrExists = true;
		}
		return substrExists;
	}


	/// <summary>
	/// Returns title attribute .
	/// </summary>
	Publication::operator const char* () const
	{
		return m_title;
	}


	/// <summary>
	/// Returns library refrence attribute .
	/// </summary>
	/// <returns></returns>
	int Publication::getRef() const
	{
		return m_libRef;
	}

	//////////// MODIFIERS ///////////////

	/// <summary>
	/// Dispalys streamable object  on ostream .
	/// </summary>
	/// <param name="os">Checks if incoming arguement is an IOS object(cin or cout) or not.</param>
	/// <returns></returns>
	std::ostream& Publication::write(std::ostream& os) const
	{
		if (!conIO(os)) 
		{
			if (m_title!= nullptr )
			{
				os << type() << '\t'
					<< m_libRef << '\t'
					<< m_shelfId << '\t'
					<< m_title << '\t'
					<< m_membership << '\t'
					<< m_date;
			}
		}

		// If the incoming ostream object is a IOS object
		else
		{
			if (m_title!=nullptr)
			{
				os << '|' << ' '; 
				os.width(SDDS_SHELF_ID_LEN);
				os << m_shelfId << ' ' << '|';

				os << ' ';
				
				/* // OLDER METHOD - DOES NOT MEET REQUIREMENTS OF MS4
				os.width(SDDS_TITLE_WIDTH);
				os.setf(std::ios::left);
				os.fill('.');
				os << m_title;
				os.unsetf(std::ios::left);
				*/
				
				// Updated method which prints the contents character by character and also the dots manually
				size_t titleLength = strlen(m_title);
				for (size_t i = 0; i < SDDS_TITLE_WIDTH; i++)
				{
					if (i < titleLength && m_title[i] != '\0') {
						os << m_title[i];
					}
					else {
						os << ".";
					}
				}
				
				os << ' ';

				os << '|' << ' ';
				if (m_membership==0)
				{
					os << " N/A ";
				}
				else
				{
					os << m_membership;
				}
				os << ' ' << '|';
				os << ' ' << m_date << ' ' << '|';
			}
		}

		return os;
	}


	/// <summary>
	/// Reads input into attributes of streamable object 
	/// </summary>
	/// <param name="istr">Checks if the istream is in not a failed state</param>
	/// <returns></returns>
	std::istream& Publication::read(std::istream& istr)
	{
		/*
		m_title = nullptr;
		resetDate();

		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		*/

		std::string tempTitle;
		std::string tempShelfID;

		std::string clearNewLine;
		Date tempDate; 
		int tempLibRef = 0;
		int tempMembership = 0;

		if (conIO(istr))
		{
			std::cout << "Shelf No: ";
			istr >> tempShelfID;

			if (strlen(tempShelfID.c_str()) != SDDS_SHELF_ID_LEN)
			{
				istr.setstate(std::ios::failbit);	
				tempShelfID = '\0';
			}

			else
			{
				strcpy(m_shelfId,tempShelfID.c_str());
				std::getline(istr, clearNewLine, '\n');
			}

			std::cout << "Title: ";
			std::getline(istr, tempTitle, '\n');

			std::cout << "Date: ";
			if (istr)
			{
				istr >> tempDate;

			}
		}
		
		else
		{
			if (!istr.fail())
			{
				istr >> tempLibRef;
				istr.ignore(1, '\t');
				
				istr >> tempShelfID;
				istr.ignore(1, '\t');

				std::getline(istr, tempTitle, '\t');

				istr >> tempMembership;
				istr.ignore(1, '\t');

				istr >> tempDate;
			}
		}

		if (!tempDate)
		{
			istr.setstate(std::ios::failbit);
		}

		else
		{	// istr is in valid state
			if (istr.good()&& strlen(tempTitle.c_str())!=0)
			{
				m_shelfId[0] = '\0';
				m_title = nullptr;
				m_title = new char[strlen(tempTitle.c_str()) + 1];

				strcpy(m_title, tempTitle.c_str());

				strcpy(m_shelfId, tempShelfID.c_str());

				m_membership = tempMembership;
				m_date = tempDate;
				setRef(tempLibRef);
			}
		}

		return istr;
		
	}

	/// <summary>
	/// Checks if Publication is in valid state 
	/// </summary>
	Publication::operator bool() const
	{
		bool valid = false;
		if (m_title!=nullptr && strlen(m_shelfId)!=0)
		{
			valid = true;
		}

		return valid;
	}

	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <param name="rhs"></param>
	Publication::Publication(const Publication& rhs)
	{
		m_libRef = rhs.m_libRef;
		m_membership = rhs.m_membership;

		strcpy(m_shelfId, rhs.m_shelfId);
		strcpy(m_title, rhs.m_title);

		m_date = rhs.m_date;
		
	}

	/// <summary>
	/// Copy assignment operator
	/// </summary>
	/// <param name="rhs"></param>
	/// <returns></returns>
	Publication& Publication::operator=(const Publication& rhs)
	{
		if (this != &rhs && rhs.m_title!=nullptr)
		{

			delete []  m_title;
			m_title = nullptr;
			resetDate();

			m_title = new char[strlen(rhs.m_title) + 1];

			m_date = Date();
			m_libRef = rhs.m_libRef;
			m_membership = rhs.m_membership;

			strcpy(m_shelfId, rhs.m_shelfId);
			strcpy(m_title, rhs.m_title);

			m_date = rhs.m_date;

		}

		return *this;
		
	}

	Publication::~Publication()
	{
		delete []  m_title;
		m_title = nullptr;
		resetDate();

		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		
	}



}