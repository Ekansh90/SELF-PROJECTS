////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Name: Ekansh	
// Seneca Student ID: 167454214
// Seneca email: ekansh@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include<iostream>
#include <string>
#include <sstream>

#include <iomanip>

namespace seneca 
{
	class Utilities
	{
	private :
		// length of token extracted - default 1
		size_t m_widthField = 1;

		// class variable - seperates token in string objects - same for all utilities object
		static char m_delimiter;

	public:
		Utilities();
		~Utilities();

		/// <summary>
		/// sets the field width of the current object to the value of parameter newWidth
		/// </summary>
		void setFieldWidth(size_t newWidth);


		/// <summary>
		/// -
		/// </summary>
		/// <returns> returns field width variable</returns
		size_t getFieldWidth() const;


		/// <summary>
		/// 1) Extracts "A SINGLE" token from string str
		/// 2) Throws exception if delimitter at next pos
		/// 3) len of token extracted = m_fieldWidth if , current val of m_fieldWidth is > len of token extracted
		/// </summary>
		/// <param name="str">single line string from which token has to be extracted</param>
		/// <param name="next_pos">beginning point to start extracting token from this position - position of next token,+1 after delimitter(not delim)</param>
		/// <param name="more">set to true if token extracted succesfully , otherwise set to false</param>
		/// <returns>If token extracted successfuly - return copy of extracted token - AFTER TRIMMING FROM BOTH SIDES</returns>
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		/// <summary>
		/// Sets delimitter for class
		/// </summary>
		/// <param name="newDelimiter">delimitter recieved which needs to be set to class var</param>
		static void setDelimiter(char newDelimiter);

		/// <summary>
		/// Returns delimitter
		/// </summary>
		static char getDelimiter();


	};

};

#endif // !SENECA_UTILITIES_H
