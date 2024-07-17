////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Name: Ekansh	
// Seneca Student ID: 167454214
// Seneca email: ekansh@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
				//m_lstItem[i] = new Item(tempToken); // make sure to delete each ptr in vector in move assignment operator + destrcutor
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

		bool result = true;
		std::for_each(m_lstItem.begin(), m_lstItem.end(),
			//[&](const Item* singleItemObj)
			[&](const std::unique_ptr<Item>& singleItemObj)
			{
				if (singleItemObj->m_isFilled == false)
					result = false;
			});
		return result;
	}




	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool result = true;

		// DONE : try doing it with an algorithm
		std::for_each(m_lstItem.begin(), m_lstItem.end(),
			//[&](const Item* singleItemObj)
			[&](const std::unique_ptr<Item>& singleItemObj)
			{
				if (singleItemObj->m_itemName == itemName && singleItemObj->m_isFilled == false)
					result = false;
			});

		return result;

	}


	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		// redundant as no return from this function
		bool orderFilledinItems = false;
		for (size_t i = 0; i < m_lstItem.size() && !orderFilledinItems; i++)
		{
			// If order(list) contains the item being handled in the station
			if (m_lstItem[i]->m_itemName == station.getItemName())
			{
				if (!m_lstItem[i]->m_isFilled) // only attempt to fill if the item is unfilled
				{
					if (station.getQuantity() > 0)
					{
						// fills order with single station item
						m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();// 
						m_lstItem[i]->m_isFilled = true;

						// subtracts 1 from inventory - as now stored in list
						station.updateQuantity();

						os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
						orderFilledinItems = true;
					}

					else
					{
						os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;

					}

				}
			}

			// do nothing - if order(list) does not contain item being handled in station
			else
			{
				;
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;

		// same logic but with algorithm

		std::for_each(m_lstItem.begin(), m_lstItem.end(),  // each element is a unique_ptr to Item type
			//[&](const Item* singleItemObject) 
			[&](const std::unique_ptr<Item>& singleItemObject) // from the iterator - reference to unique ptr of item type
			{
				std::string filTrue = "TO BE FILLED";
				if (singleItemObject->m_isFilled == true)
				{
					filTrue = "FILLED";
				}
				os << "[" << std::right << std::setfill('0') << std::setw(6) << singleItemObject->m_serialNumber << "]";
				os << std::left << std::setfill(' ') << " " << std::setw(m_widthField) << singleItemObject->m_itemName << " - ";
				os << filTrue << std::endl;
			});

	}

	// COPY OPERATIONS
		// deleted copy operations - copy constructor throws exception if copy assignment operator called
	CustomerOrder::CustomerOrder(const CustomerOrder& rhs)
	{
		*this = rhs;
	}

	CustomerOrder& CustomerOrder:: operator=(const CustomerOrder& rhs)
	{
		throw "copy assignment operator called";
		return *this;
	}

	// DONE : MOVE OPERATIONS
	CustomerOrder::CustomerOrder(CustomerOrder&& rhs) noexcept
	{
		*this = std::move(rhs);
	}

	CustomerOrder& CustomerOrder:: operator=(CustomerOrder&& rhs)noexcept
	{
		if (this != &rhs)
		{
			/*
			for (size_t i = 0; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
			}
			*/

			m_name = rhs.m_name;
			m_product = rhs.m_product;
			m_cntItem = rhs.m_cntItem;
			m_lstItem = std::move(rhs.m_lstItem); // should call move assignment operator for vector TO TRANSFER OWNERSHIP
			//m_lstItem = rhs.m_lstItem; // INSTEAD OF COPYING

			//rhs.m_lstItem.clear() ; // CLEAR DOES NOT DEALLOCATE RESOURCES - JUST EMPTIES VEFOTR
			rhs.m_cntItem = 0;
			rhs.m_product = "";
			rhs.m_name = "";
		}

		return *this;
	}


	CustomerOrder:: ~CustomerOrder()
	{
		m_name = "";
		m_product = "";

		/*
		* // only needed if not using a unique ptr
		for (size_t i = 0; i < m_cntItem; i++)
		{
			//delete m_lstItem[i];
		}
		*/


		m_cntItem = 0;

	}


};