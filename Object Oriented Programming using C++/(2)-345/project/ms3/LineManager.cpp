////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Name: Ekansh	
// Seneca Student ID: 167454214
// Seneca email: ekansh@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "LineManager.h"

namespace seneca {


    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
    {
        
        std::ifstream inputFile(file);
        if (!inputFile.is_open()) {
            std::cerr << "Error: Unable to open file " << file << std::endl;
            // Handle error (throw exception, return, or other)
            return;
        }

        // Read and parse each record in the file
        std::string line;
        while (std::getline(inputFile, line)) {

            std::istringstream iss(line);
            std::string workstationName, nextWorkstationName;

            if (std::getline(iss, workstationName, '|') && std::getline(iss, nextWorkstationName)) {

                // Find workstations with workstationName and nextWorkstationName
                auto firstIT = std::find_if(stations.begin(), stations.end(),
                    [&](Workstation* ws) {
                        return ws->getItemName() == workstationName;
                    });

                auto nextIt = std::find_if(stations.begin(), stations.end(),
                    [&](Workstation* ws)
                    {
                        return ws->getItemName() == nextWorkstationName;
                    });


                // Ensure first workstation are found
                if (firstIT != stations.end()) {
                    // Set next workstation pointer
                    m_activeLine.push_back(*firstIT);
                    m_activeLine.at(m_activeLine.size() - 1)->setNextStation(*nextIt);
                    //              can also use m_activeLine.back() , to get the last element pushed  recently
                }


            }

            // next station is nullptr , getline failed for nextWorkstationName
            else {

                // Find workstations with workstationName 
                auto firstIT = std::find_if(stations.begin(), stations.end(),
                    [&](Workstation* ws) {
                        return ws->getItemName() == workstationName;
                    });

                if (firstIT != stations.end()) {
                    // Set next workstation pointer
                    m_activeLine.push_back(*firstIT);
                    m_activeLine.at(m_activeLine.size() - 1)->setNextStation(nullptr);
                }

            }
        }

        // finding first workstation

        auto first = std::find_if(stations.begin(), stations.end(), [&](Workstation* station) {
            for (Workstation* other : stations)
            {
                if (other != station && other->getNextStation() == station)
                {
                    return false; // Found another workstation pointing to this station
                }
            }
            return true; // No other workstation points to this station
            });



        if (first != stations.end())
            m_firstStation = *first;




        //m_firstStation = m_activeLine.front();
        m_cntCustomerOrder = g_pending.size();
        /////////////////////////////////////////////////////////////////////////////////////////////////

        // previously implemented for loop method 
         /*
        std::ifstream fileObj(file);
        if (!fileObj)
        {
            throw std::string("Unable to open [") + file + "] file.";
        }

        size_t i = 0;
        while (!fileObj.eof())
        {

            seneca::Utilities m_utilityObj;
            bool more = false;
            size_t startPos = 0;

            std::string str;

            std::string firstStation;
            std::string nextStation;


            std::getline(fileObj, str);
            firstStation = m_utilityObj.extractToken(str, startPos, more);
            // if there's also next station stored in file
            if (more)
            {
                nextStation = m_utilityObj.extractToken(str, startPos, more);
            }


            for (size_t i = 0; i < stations.size(); i++)
            {
                if (stations[i]->getItemName() == firstStation)
                {
                    for (size_t j = 0; j < stations.size(); j++)
                    {
                        if (stations[j]->getItemName() == nextStation)
                        {
                            stations[i]->setNextStation(stations[j]);
                        }
                    }
                    m_activeLine.push_back(stations[i]);
                }
            }
        }
        // m_firstStation = m_activeLine.front(); wrong
        m_cntCustomerOrder = g_pending.size();
        */
    }

    bool LineManager::run(std::ostream& os) 
    {

        static size_t executionCount = 0;
        executionCount++;
        os << "Line Manager Iteration: " << executionCount << std::endl;

        // moves the order at front of g_pending to m_firstStation and removes element from g_pending		
        if (g_pending.empty() == false)
        {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }

        // attempts to fill each station on line
        std::for_each(m_activeLine.begin(), m_activeLine.end(),
            [&](Workstation* ws) 
            {
                ws->fill(os);
            });

        // attempts to move order on line
        std::for_each(m_activeLine.begin(), m_activeLine.end(),
            [&](Workstation* ws)
            {
                ws->attemptToMoveOrder();
            });

        // On attempting to move - either order gets completed or incompleted
        size_t ordersMoved = g_completed.size() + g_incomplete.size();

        bool allOrdersMoved = false;
        // while loop in main ms3.cpp exits until all orders are processed
        if (ordersMoved == m_cntCustomerOrder)
        {
            allOrdersMoved = true;
        }


        return allOrdersMoved;
    }






	void LineManager::reorderStations() 
	{
        // 1. sort by length 
        std::sort(m_activeLine.begin(), m_activeLine.end(),
            [](const Workstation* ws1, const Workstation* ws2)
            {
                return ws1->getItemName().length() < ws2->getItemName().length();
            }
        );

        std::vector<Workstation*> sortedLine;
        sortedLine.push_back(m_activeLine.front());

        // 2. Checks if each element starting from 1st element of sorted line (-1 before reaching the station with next station as nullptr)
        for (size_t i = 0; i < m_activeLine.size() - 1; i++)
        {
            if (sortedLine[i]->getNextStation()) // next station is not null ptr / end of line
            {
                for (size_t j = 0; j < m_activeLine.size(); j++)
                {
                    if (m_activeLine[j]->getNextStation()) // next station is not null ptr
                    {
                        if (sortedLine[i]->getNextStation()->getItemName() == m_activeLine[j]->getItemName())
                        {
                            sortedLine.push_back(m_activeLine[j]);
                        }
                    }

                }
            }
        }

        // 3. Find station which has next station as nullptr
        for (size_t i = 0; i < m_activeLine.size(); i++)
        {
            if (m_activeLine[i]->getNextStation() == nullptr)
            {
                sortedLine.push_back(m_activeLine[i]);
            }

        }

        m_activeLine = sortedLine;
	}

	void LineManager::display(std::ostream& os) const 
	{
		std::for_each(m_activeLine.begin(), m_activeLine.end(),
			[&](const Workstation* station) {
				station->display(os);
			});
	}
};