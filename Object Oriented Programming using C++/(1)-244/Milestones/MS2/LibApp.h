#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

namespace sdds 
{
   class LibApp 
   {
	   // flag to report any changes made to data , returns true if changes are made
	   bool m_changed;

	   Menu m_mainMenu;

	   Menu m_exitMenu;

	   // Presents user another menu to confirm selection
	   bool confirm(const char* message);

	   // prints Message: "Loading Data"
	   void load();  

	   // prints Message: "Saving Data"
	   void save();  

	   // prints Message: "Searching for publication"
	   void search();  

	   /// <summary>
	   /// Calls the search() method.
	   /// prints "Returning publication" < NEWLINE >
	   /// prints "Publication returned" < NEWLINE >
	   /// sets m_changed to true;
	   /// </summary>
	   void returnPub();  

	    /// <summary>
		/// prints "Adding new publication to library"+newline
		/// calls the confirm method with "Add this publication to library?"
		/// if confirm returns true, it will set m_changed to true and prints "Publication added" + newline
		/// </summary>
	   void newPublication();

	   /// <summary>
	   /// prints "Removing publication from library"+newline
	   /// calls the search method 
	   /// calls the confirm method with "Remove this publication from the library?"
	   /// if confrim returns true, it will set m_changed to true and prints "Publication removed" + newline
	   /// </summary>
	   void removePublication();

	   /// <summary>
	   /// calls the search method
	   /// calls the confirm method with Check out publication ? "
	   /// if confirm returns true, it will set m_changed to true and prints "Publication checked out" + newline
	   /// </summary>
	   void checkOutPub();

   public :
	   LibApp();

	   // "Main" function which prints menu and asks user for selection
	   void run();		
   };
}
#endif // !SDDS_LIBAPP_H



