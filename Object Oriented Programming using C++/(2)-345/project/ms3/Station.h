////////////////////////////////////////////////////////////////////////////////////////////////////////

// Name: Ekansh	
// Seneca Student ID: 167454214
// Seneca email: ekansh@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <iostream>
#include <string>

#include "Utilities.h"

namespace seneca
{
	class Station
	{
	private:
		int m_stationID = 0;
		std::string m_stationName = "";
		std::string m_stationDesc = "";
		unsigned int m_serialNumber = 0u;
		unsigned int m_numOfItems = 0u;

		// the maximum number of characters required to print to the screen the item name of station
		static size_t m_widthField;

		// variable used to generate IDs for new instances of Station. 
		// Every time a new instance is created, the current value of the id_generator is stored in that instance, and id_generator is incremented.
		static size_t id_generator;


	public:
		Station();
		~Station();

		// TODO : Check if works

		/// <summary>
		/// Reads single line from str and stores 4 tokens into respective fields
		/// In the order name , serialNum ,qunatity , desc
		/// Before extarcting description updates field variable to max val of both utilities and station  field variables
		/// Delimitter specified by client - dont worry about it
		/// </summary>
		Station(const std::string& str);


		/// <summary>
		/// returns m_stationName
		/// </summary>
		/// <returns></returns>
		const std::string& getItemName() const;


		/// <summary>
		///  returns the next serial number to be used on the assembly line and increments m_serialNumber
		/// </summary>
		/// <returns>m_serialNumber</returns>
		size_t getNextSerialNumber();


		/// <summary>
		/// returns the remaining quantity of items in the Station object
		/// </summary>
		/// <returns>m_numOfItems</returns>
		size_t getQuantity() const;


		/// <summary>
		/// subtracts 1 from the available quantity; should not drop below 0.
		/// </summary>
		void updateQuantity();

		/// <summary>
		/// Inserts station object to ostream in formatted way.
		/// </summary>
		/// <param name="os"></param>
		/// <param name="full"></param>
		void display(std::ostream& os, bool full) const;

		int returnStationId()const 
		{
			return m_stationID;
		}
	};




};

#endif // !SENECA_STATION_H
