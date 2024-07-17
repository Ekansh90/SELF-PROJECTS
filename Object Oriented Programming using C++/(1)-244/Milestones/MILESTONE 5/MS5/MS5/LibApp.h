
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include <iomanip>
#include "Menu.h"
#include "Publication.h"
#include "Book.h"
#include "PublicationSelector.h"


using namespace std;
#define MAX_FILE_LEN 256

 

namespace sdds
{

	#define SEARCH_ALL_PUBLICATIONS 0
	#define SEARCH_LOANED_PUBLICATIONS 1
	#define SEARCH_AVAILABLE_PUBLICATIONS 2


	class LibApp
	{
		// flag to report any changes made to data , returns true if changes are made
		bool m_changed;

		Menu m_mainMenu;

		Menu m_exitMenu;

		/// <summary>
		/// Presents the user to confirm their choice .
		/// </summary>
		/// <param name="message"></param>
		/// <returns>Message that user recieves during confirm prompt</returns>
		bool confirm(const char* message);

		/// <summary>
		/// Opens m_fileName  and stores input to PPA publication pointers array .
		/// Sets up the reference number of the last publication read .
		/// </summary>
		void load();

		/// <summary>
		/// Opens m_fileName for writing data to . 
		/// Only writes the Publications whose reference number is not 0 .
		/// </summary>
		void save();  ////////////////////////////////////////

		/// <summary>
		/// Checks the type of new publication being added 
		/// Adds publication to the end of existing publications
		/// </summary>
		void newPublication(); ////////////////////////////////////////

		/// <summary>
		/// Searches through all the publications and finds the Reference Id of the one to remove
		/// Sets it's refId to 0 to show that it is deleted from the system .
		/// </summary>
		void removePublication();


		/// <summary>
		/// Searches through the loaned publications 
		/// Calculates penalty on the basis of days passed since publication was borrowed
		/// No penalty if within 15 days , 0.5 cents for each day after the 15th day
		/// If Publication is returned successfully , sets its membership id to 0 .
		/// </summary>
		void returnPub();

		/// <summary>
		/// Gets publication title from user and searches throughout the Publications array
		/// based on title input given by user and mode in which the search method has been run
		/// </summary>
		/// <param name="mode">User can search PPA via different modes</param>
		/// <returns></returns>
		int search(int mode);

		/// <summary>
		/// Searches through the publications which have not yet been borrowed 
		/// Finds reference Id and issues it to a member .
		/// </summary>
		void checkOutPub();


		///////////////// NEWER MODIFICATIONS - ACCORDING TO MS5 /////////////////////

		// Variable to store the fileName we will be writing data to and from .
		char m_fileName[MAX_FILE_LEN]{};

		// Array to store publications
		// Populated with publication data file when LibApp instantiated - constructor 
		Publication* PPA[SDDS_LIBRARY_CAPACITY]{};

		// number of publications loaded
		int NOLP{ 0 };

		// LAST LIB REFERENCE num
		// to assign new lib reference numbers when new publications are added
		int LLRN;

		// Menu to store and for user to choose publication type from ("Book or Publication")
		Menu m_pubType;

	public:
		LibApp(const char* fileName = nullptr);

		// "Main" function which prints menu and asks user for selection
		void run();

		~LibApp();

		///////////////////
		// New methods
		Publication* getPub(int libRef); //////////////////////////////////////


		// prints the publication with the library reference number "ref:
		void prnPub(Publication* p[], int size, int ref) {
			int i;
			for (i = 0; i < size; i++) {
				if (ref == p[i]->getRef()) {
					cout << *p[i] << endl;
					i = size; // Exit the loop.
				}
			}
		}

	};
}
#endif // !SDDS_LIBAPP_H



