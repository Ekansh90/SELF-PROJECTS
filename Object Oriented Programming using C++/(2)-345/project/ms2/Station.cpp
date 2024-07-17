

#include "Station.h"
namespace seneca 
{
	size_t Station::id_generator = 0;
	size_t Station::m_widthField = 0;
	//int Station :: m_stationID = 0;

	Station::Station()
	{

		m_widthField = 0;
		id_generator = 0;

		// done :: should this be in the one argument constructor
		//m_widthField++;
		//id_generator++;
	}

	Station::~Station()
	{
		//m_stationID = 0;
		//Station::id_generator = 0;
	}

	const std::string& Station::getItemName() const { return m_stationName; }
	size_t Station::getNextSerialNumber() { return m_serialNumber++; }
	size_t Station::getQuantity() const { return m_numOfItems; }

	void Station::updateQuantity()
	{
		if (m_numOfItems > 0)
			m_numOfItems--;
	}

	void Station::display(std::ostream& os, bool full) const
	{

		os << std::right << std::setfill('0') << std::setw(3) << m_stationID;
		os << " | ";
		os << std::left << std::setfill(' ') << std::setw(m_widthField) << getItemName();
		os << " | ";
		os << std::right << std::setfill('0') << std::setw(6) << m_serialNumber;

		if (!full) 
		{
			os << " | ";
		}

		else if (full)
		{
			os << " | ";
			os << std::setw(4) << std::setfill(' ') << getQuantity();
			os << " | " << std::left << m_stationDesc;
		}

		os << std::endl;
	}

	Station::Station(const std::string& str)
	{
		seneca::Utilities m_utilityObj;
		bool more = false;
		size_t startPos = 0;


		try // extractToken throws error - ideal to put in try-catch block
		{
			m_stationName = m_utilityObj.extractToken(str, startPos, more);
			m_serialNumber = stoi(m_utilityObj.extractToken(str, startPos, more));
			m_numOfItems = stoi(m_utilityObj.extractToken(str, startPos, more));


			if (m_widthField > m_utilityObj.getFieldWidth()); // do nothing - if current field width already greater than that of token extracted.
			else if (m_widthField < m_utilityObj.getFieldWidth())
			{
				m_widthField = m_utilityObj.getFieldWidth();
			}

			m_stationDesc = m_utilityObj.extractToken(str, startPos, more);
			// static member can store the value for all instances - each time a new object created and stored we increment class variable and store it in station id
			m_stationID = ++id_generator;


		}
		catch (const std::exception&)
		{
			throw"delimitter found at next pos after reading";
		}

	}
};