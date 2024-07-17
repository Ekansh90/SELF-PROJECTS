////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Name: Ekansh	
// Seneca Student ID: 167454214
// Seneca email: ekansh@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Utilities.h"

namespace seneca 
{
	// initializng static member of class
	char Utilities::m_delimiter;
	Utilities::Utilities()
	{
		;
	}

	Utilities::~Utilities()
	{
		;
	}

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}

	// DONE  : CHECK WORKING
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		// lambda function to remove whitespaces from beginning and end of each field
		auto trimSubstr = [&](std::string& tempSubStr)
			{
				size_t strStarts, strEnds, strlen = 0;
				if (tempSubStr.length() != 0)
				{
					strStarts = tempSubStr.find_first_not_of(' ');
					strEnds = tempSubStr.find_last_not_of(" ") + 1;
					strlen = strEnds - strStarts;
					tempSubStr = tempSubStr.substr(strStarts, strlen);
				}

			};
		//////////////////////////////////////////////////////

		std::string tempToken = "";
		more = false;

		if (str[next_pos] == getDelimiter())
		{
			throw std::runtime_error("Delimitter found at next pos");
			// can also use just throw "string"
		}

		//////////////////////////////////////////////////////


		else
		{
			size_t nextDelimPos = str.find(getDelimiter(), next_pos); // if cant find - find sets nextDelimPos to max val of size_t
			if (nextDelimPos > str.length()) // if reached end of line 
			{
				nextDelimPos = str.length();

				tempToken = str.substr(next_pos, nextDelimPos - next_pos);
				trimSubstr(tempToken);// trim whitespaces from both sides
				next_pos = nextDelimPos;
				more = false;

			}

			else
			{
				tempToken = str.substr(next_pos, nextDelimPos - next_pos);
				trimSubstr(tempToken);
				next_pos = nextDelimPos + 1;
				more = true;
			}

			/////////////////////////////////////// setting up  m_widthField
			size_t tokenLen = tempToken.length();
			if (tokenLen != 0)
			{
				if (tokenLen > getFieldWidth())
				{
					// update m_fieldWidth if lenght of token extracted greater than 
					setFieldWidth(tokenLen);
				}

			}
		}


		return tempToken;
	}
};