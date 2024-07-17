////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Name: Ekansh	
// Seneca Student ID: 167454214
// Seneca email: ekansh@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H

#include <fstream>
#include <algorithm>
#include <functional>

#include "Workstation.h"

namespace seneca {
    class LineManager {

        // vector of workstation pointers
        std::vector<Workstation*> m_activeLine;
        //std::vector<std ::unique_ptr<Workstation> > m_activeLine;

        size_t m_cntCustomerOrder{};

        // pointer to first workstation 
        Workstation* m_firstStation=nullptr;

    public:
        LineManager(const std::string& file, const std::vector<Workstation*>& stations); 

        /// <summary>
        /// Sorts and transforms m_activeLine 
        /// </summary>
        void reorderStations();

        bool run(std::ostream& os);

        void display(std::ostream& os) const;
    };
}
#endif // !SENECA_LINEMANAGER_H