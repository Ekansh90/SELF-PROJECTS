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


#ifndef _SDDS_LIB_H
#define _SDDS_LIB_H

#include <iostream>

namespace sdds
{
    // maximum number of day a publication can be borrowed with no penalty
    const int SDDS_MAX_LOAN_DAYS = 15;

    // The width in which the title of a publication should be printed on the console
    const int SDDS_TITLE_WIDTH = 30;

    // The width in which the author name of a book should be printed on the console
    const int SDDS_AUTHOR_WIDTH = 15;

    // The width in which the shelf id of a publication should be printed on the console
    const int SDDS_SHELF_ID_LEN = 4;
    
    // Maximum number of publications the library can hold.
    const int SDDS_LIBRARY_CAPACITY = 5000;
}

#endif // !_SDDS_LIB_H
