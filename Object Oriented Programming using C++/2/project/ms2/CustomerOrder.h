////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Name: Ekansh	
// Seneca Student ID: 167454214
// Seneca email: ekansh@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H

#include <iostream>
#include <string>
#include <iomanip>

#include <vector>
#include <algorithm>

#include <memory>

#include "Station.h"

namespace seneca 
{
	class CustomerOrder
	{
	private:
		struct Item {
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};

		// customer name
		std::string m_name = "";

		// product name
		std::string m_product = "";

		// number of items in customer order
		size_t m_cntItem = 0 ; 

		// vector of item pointers
		std::vector< std::unique_ptr<Item>> m_lstItem; // use back inserter 
		//std::vector<Item*> m_lstItem;

		// class member - width of field
		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);

		// COPY OPERATIONS
		// deleted copy operations - copy constructor throws exception if copy assignment operator called
		CustomerOrder(const CustomerOrder& rhs) 
		{
			*this = rhs;
			/*
			try
			{
				*this = rhs;
			}
			catch (const std::exception&)
			{
				throw "copy assignment operator called";
			}
			*/
		}

		// should this be deleted
		CustomerOrder& operator=(const CustomerOrder& rhs) 
		{
			throw "copy assignment operator called";
			return *this ;
		}

		// TODO : MOVE OPERATIONS
		CustomerOrder(CustomerOrder&& rhs) noexcept 
		{
			*this = std::move(rhs);
		}

		CustomerOrder& operator=(CustomerOrder&& rhs)noexcept 
		{
			if (this != &rhs) 
			{
				m_name = rhs.m_name;
				m_product = rhs.m_product;
				m_cntItem = rhs.m_cntItem;
				//m_lstItem = rhs.m_lstItem; // should call move assignment operator for vector
				m_lstItem = std::move(rhs.m_lstItem); // should call move assignment operator for vector

				/*
				for (size_t i = 0; i < m_lstItem.size(); i++)
				{
					delete rhs.m_lstItem[i];
				}
				*/

				//rhs.m_lstItem.clear() ;
				rhs.m_cntItem = 0;
				rhs.m_product = "";
				rhs.m_name = "";
			}

			return *this;
		}

		//~CustomerOrder(); 


		~CustomerOrder()
		{
			m_name = "";
			m_product = "";
			//delete m_lstItem;
			
			//m_lstItem.clear();
			
			for (size_t i = 0; i < m_cntItem; i++)
			{
				//delete m_lstItem[i];
			}
			
			m_cntItem = 0;
			
		}
			
		

		/// <summary>
		/// Checks if all items in order(checks for each item in container) are filled 
		/// </summary>
		bool isOrderFilled() const;

		/// <summary>
		/// Checks if all items of the name in paramter are filled 
		/// </summary>
		bool isItemFilled(const std::string& itemName) const;

		
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;

	};

	
};


#endif // !SENECA_CUSTOMERORDER_H
