

#include "CustomerOrder.h"

namespace seneca 
{
	// instantiating instance variable
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder(const std::string& str)
	{
		seneca::Utilities m_utilityObj;
		bool more = false;
		size_t startPos = 0;

		try
		{
			m_name = m_utilityObj.extractToken(str, startPos, more);
			m_product = m_utilityObj.extractToken(str, startPos, more);

			size_t startReadFrom = startPos;
			size_t recordsInListItems = 0;

			// calculating number of items in list
			for (size_t i = 0; more == true; i++)
			{
				std::string tempToken = m_utilityObj.extractToken(str, startPos, more);
				recordsInListItems++;
			}

			startPos = startReadFrom;
			more = true;

			// resizing the list with size calculated
			m_lstItem.resize(recordsInListItems); 
			m_cntItem = recordsInListItems;
			for (size_t i = 0; more == true; i++)
			{
				std::string tempToken = m_utilityObj.extractToken(str, startPos, more);
				m_lstItem[i] = std::make_unique<Item>(tempToken);
			}

			// set up field width for printing purposes
			if (m_widthField > m_utilityObj.getFieldWidth()); // do nothing - if current field width already greater than that of token extracted.
			else if (m_widthField < m_utilityObj.getFieldWidth())
			{
				m_widthField = m_utilityObj.getFieldWidth();
			}
		}
		catch (const std::exception&)
		{
			throw"delimitter found at next pos after reading/no more to read";
		}

	}

	bool CustomerOrder::isOrderFilled() const
	{
		// do it with an algorithm
		bool result = true;

		
		for (size_t i = 0; i < m_lstItem.size(); i++)
		{
			if (m_lstItem[i]->m_isFilled == false)
			{
				result = false;
			}
		}
		

		// just checking
		/*
		std::for_each(m_lstItem.begin(), m_lstItem.end(), 
			[&](const std::unique_ptr<Item>& singleItemObj) 
			{
				if (singleItemObj->m_isFilled == false)
					result = false;
			});

		*/
		
		return result;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool result = true;

		
		for (size_t i = 0; i < m_lstItem.size() && result == true ; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName)
			{
				if (m_lstItem[i]->m_isFilled == false)
				{
					result = false;
				}
			}

		}
		

		// DONE : try doing it with an algorithm

		/*
		std::for_each(m_lstItem.begin(), m_lstItem.end(),
			[&](const std::unique_ptr<Item>& singleItemObj)
			{
				if (singleItemObj->m_itemName == itemName && singleItemObj->m_isFilled == false)
					result = false;
			});

		*/

		return result;

	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		bool orderFilledinItems = false;
		
		// checking if 		// order contains item being handled by station parameter
		for (size_t i = 0; i < m_lstItem.size() && orderFilledinItems != true ; i++)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName()) // item recieved in parameter exists in list of items
			{
				if (station.getQuantity() >= 1)
				{
					// fills order with single station item
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();// 
					m_lstItem[i]->m_isFilled = true;

					// subtracts 1 from inventory - as now stored in list
					station.updateQuantity();

					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
					orderFilledinItems = true;

				}

				else if (station.getQuantity() == 0)
				{
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;

				}
			}

		}





	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;
		
		for (size_t i = 0; i < m_lstItem.size(); i++)
		{
			std::string filTrue = "TO BE FILLED";
			if (m_lstItem[i]->m_isFilled == true)
			{
				filTrue = "FILLED";
			}
			os << "[" << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber << "]" << std::setfill(' ') << " " << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
			os << filTrue << std::endl;

		}
		

		/*
		std::for_each(m_lstItem.begin(), m_lstItem.end(),  // each element is a unique_ptr to Item type
			[&](const std::unique_ptr<Item>& singleItemObject) // from the iterator - reference to unique ptr of item type
			{
				std::string filTrue = "TO BE FILLED";
				if (singleItemObject->m_isFilled == true)
				{
					filTrue = "FILLED";
				}
				os << "[" << std::setfill('0') << std::setw(6) << singleItemObject->m_serialNumber << "]" << std::setfill(' ') << " " << std::setw(m_widthField) << singleItemObject->m_itemName << " - ";
				os << filTrue << std::endl;
			});
		*/
	}



};