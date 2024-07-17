////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Name: Ekansh	
// Seneca Student ID: 167454214
// Seneca email: ekansh@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H

#include <deque>
#include "CustomerOrder.h"

namespace seneca {



    // global variables - double ended queues - declared here but again need to be defined in .cpp file

    extern std::deque<CustomerOrder> g_pending;       // order to be placed - at the first station
    extern std::deque<CustomerOrder> g_completed;     //orders that have been removed from last station and filled completely
    extern std::deque<CustomerOrder> g_incomplete;    // orders that have been removed but not filled completely

    class Workstation : public Station
    {
    private:

        //			list of orders(needing service) that need to be filled - sent from g_pending
        std::deque<CustomerOrder> m_orders{};

        //			after one order has been serviced moved to next station for servicing
        Workstation* m_pNextStation = nullptr;


    public:


        bool attemptToMoveOrder();

        //Workstation();

        /// <summary>
        /// One arguement constructor takes unmodifiable string
        /// </summary>
        /// <param name="str">Pass string to Station-1 arg constructor</param>
        Workstation(const std::string& str);

        /// <summary>
        /// Fills order at the front of the queue if there are existing CustomerOrders
        /// </summary>
        /// <param name="os">ostream object to pass to fillItem</param>
        void fill(std::ostream& os);

        /// <summary>
        /// Stores address recieved in param to m_pNextStation
        /// </summary>
        /// <param name="station">store in m_pNextStation</param>
        void setNextStation(Workstation* station = nullptr);

        /// <summary>
        /// Returns Address of m_pNextStation
        /// </summary>
        /// <returns></returns>
        Workstation* getNextStation() const;

        /// <summary>
        /// inserts into ostream in a formatted way
        /// </summary>
        /// <param name="os"></param>
        void display(std::ostream& os) const;

        /// <summary>
        /// Moves Order referenced in paramter to the end of queue
        /// </summary>
        /// <param name="newOrder">move to end of queue</param>
        /// <returns></returns>
        Workstation& operator+=(CustomerOrder&& newOrder);

        // copy and move operations deleted
        Workstation(const Workstation& rhs) = delete;
        Workstation& operator=(const Workstation& rhs) = delete;
        Workstation(Workstation&& rhs) = delete;
        Workstation& operator=(Workstation&& rhs) = delete;




    };
};
#endif // !SENECA_WORKSTATION_H