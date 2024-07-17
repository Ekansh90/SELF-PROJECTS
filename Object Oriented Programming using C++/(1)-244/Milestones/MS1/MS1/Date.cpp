// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
namespace sdds {


    bool Date::validate()
    {
        errCode(NO_ERROR);

        if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
            errCode(YEAR_ERROR);
        }
        else if (m_mon < 1 || m_mon > 12) {
            errCode(MON_ERROR);
        }
        else if (m_day < 1 || m_day > mdays()) {
            errCode(DAY_ERROR);
        }

        // returns true if date is in incorrect state
        return !bad();
    }

    int Date::mdays()const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));

    }

    // returns current system year - 2021 for sem
    int Date::systemYear()const
    {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        return lt.tm_year + 1900;
    }

    // sets the members to values of current date
    void Date::setToToday()
    {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        m_day = lt.tm_mday;
        m_mon = lt.tm_mon + 1;
        m_year = lt.tm_year + 1900;
        errCode(NO_ERROR);

    }

    // Returns days since 00001/01/01
    int Date::daysSince0001_1_1()const
    { // Rata Die day since 0001/01/01
        int ty = m_year;
        int tm = m_mon;
        if (tm < 3) {
            ty--;
            tm += 12;
        }
        return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;

    }

    // constructor which sets up current date and
    Date::Date() :m_CUR_YEAR(systemYear())  // constructor always runs , hence m_CUR_YEAR will always be initialized using the systemYear()
    {
        setToToday();
    }

    // sets date values from the client code  in main and sets up the error accordingly using validate()
    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear())
    {
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }

    // returns the string value for the error
    const char* Date::dateStatus()const {
        return DATE_ERROR[errCode()];
    }

    // returns m_cur_year
    int Date::currentYear()const {
        return m_CUR_YEAR;
    }


    void Date::errCode(int readErrorCode) {
        m_ErrorCode = readErrorCode;
    }

    // returns error code or 0 if date is valid
    int Date::errCode()const {
        return m_ErrorCode;
    }

    // returns true if there is no error , date is valid
    bool Date::bad()const {
        return m_ErrorCode != 0;
    }


    // overloaded insertion operator to call write method
    ostream& operator<<(ostream& os, const Date& RO) {
        return RO.write(os);
    }

    // overloading extraction operator to call read method
    istream& operator>>(istream& is, Date& RO) {
        return RO.read(is);
    }


    std::istream& Date::read(std::istream& is)
    {
        // reads a date from the console in the following format YYYY/MM/DD as follows

        // cleans error code
        errCode(0);
        char delimitter{};


        is >> m_year >> delimitter >> m_mon >> delimitter >> m_day;
        if (is.fail())
        {
            errCode(CIN_FAILED);
            is.clear();

            //m_year, m_day, m_day = 0;
        }

        else
        {
            validate();
        }

        is.ignore(1000, '\n');
        return is;


    }


    std::ostream& Date::write(std::ostream& os)const
    {

        if (bad())
        {
            os << dateStatus();
        }

        else
        {

            os << m_year;

            os << "/";

            os.setf(ios::right);
            os.width(2);
            os.fill('0');
            os << m_mon;
            os.unsetf(ios::right);

            os << "/";
            os.setf(ios::right);
            os.width(2);
            os.fill('0');
            os << m_day;
            os.unsetf(ios::right);

            os.fill();


        }

        return os;
    }

    bool Date :: operator ==(const Date& d2)const
    {
        return daysSince0001_1_1() == d2.daysSince0001_1_1();
    }

    bool Date :: operator !=(const Date& d2)const
    {
        return daysSince0001_1_1() != d2.daysSince0001_1_1();
    }

    bool Date :: operator >=(const Date& d2)const
    {
        return daysSince0001_1_1() >= d2.daysSince0001_1_1();

    }

    bool Date :: operator <=(const Date& d2)const
    {
        return daysSince0001_1_1() <= d2.daysSince0001_1_1();
    }

    bool Date:: operator <(const Date& d2)const
    {
        return daysSince0001_1_1() < d2.daysSince0001_1_1();
    }

    bool Date :: operator >(const Date& d2)const
    {

        return daysSince0001_1_1() > d2.daysSince0001_1_1();
    }

    int Date :: operator -(const Date& d2)const
    {
        return (daysSince0001_1_1() - d2.daysSince0001_1_1());
    }

    Date :: operator bool()const
    {
        bool isDateValid = false;
        if ((m_year <= currentYear() && m_year >= MIN_YEAR) &&
            (m_mon <= 12 && m_mon >= 1) &&
            (m_day <= 31 && m_day >= 1)
            )
        {
            isDateValid = true;
        }

        return isDateValid;

    }


}
