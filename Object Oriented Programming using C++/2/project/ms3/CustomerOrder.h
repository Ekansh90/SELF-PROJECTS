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
		size_t m_cntItem = 0;

		// vector of item pointers
		std::vector< std::unique_ptr<Item>> m_lstItem; // use back inserter 

		//std::vector<Item*> m_lstItem;

		// class member - width of field
		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);

		CustomerOrder(const CustomerOrder& rhs);
		CustomerOrder& operator=(const CustomerOrder& rhs);
		CustomerOrder(CustomerOrder&& rhs) noexcept;
		CustomerOrder& operator=(CustomerOrder&& rhs)noexcept;
		~CustomerOrder();



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
