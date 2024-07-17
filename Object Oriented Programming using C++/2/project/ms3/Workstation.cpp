////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Name: Ekansh	
// Seneca Student ID: 167454214
// Seneca email: ekansh@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Workstation.h"

namespace seneca {


    std::deque<CustomerOrder> g_pending;
    std::deque<CustomerOrder> g_completed;    
    std::deque<CustomerOrder> g_incomplete;


    Workstation::Workstation(const std::string& str) : Station(str)
    {
        ;
    }

    void Workstation::fill(std::ostream& os)
    {
        if (m_orders.size() != 0)
        {
            // m_orders.front().fillItem(*m_pNextStation, os);
            m_orders.front().fillItem(*this, os);
            
        }
    }

    bool Workstation::attemptToMoveOrder() {
        bool moveSuccess = false;

        if (m_orders.size() != 0) {

            // item name is filled , cannot be serviced anymore
            if (m_orders.front().isItemFilled(this->getItemName()) || (getQuantity() < 1))
            {
                // next station exists not null ptr
                if (m_pNextStation)
                {
                    *m_pNextStation += std::move(m_orders.front());
                    m_orders.pop_front();
                    moveSuccess = true;
                }

                // if the order is filled at front move to completed
                else if (m_orders.front().isOrderFilled())
                {
                    g_completed.push_back(std::move(m_orders.front()));
                    m_orders.pop_front();
                    moveSuccess = true;

                }

                else
                {
                    g_incomplete.push_back(std::move(m_orders.front()));
                    m_orders.pop_front();
                    moveSuccess = true;

                }
            }
        }

        return moveSuccess;
    }

    void Workstation::setNextStation(Workstation* station)
    {
        m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const
    {
        return m_pNextStation;
    }



    void Workstation::display(std::ostream& os) const
    {

        if (m_pNextStation != nullptr)
        {
            os << this->getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
        }

        else
        {
            os << this->getItemName() << " --> " << "End of Line" << std::endl;

        }
    }


    Workstation& Workstation :: operator+=(CustomerOrder&& newOrder)
    {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }

}