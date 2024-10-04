Student Management System  :
The Student Management System is a Python-based application integrated with MySQL to manage student admissions, sports activities, and fees details. 
Below is a summary of the system's main components and functionality:

1. Main Module (main.py)
Purpose: Serves as the entry point of the application, providing a menu to access different modules (Admission, Sports, Fees).
Functionality:
Users can select from Admission Details, Sports Details, or Fees Details.
Based on the selection, corresponding functions from other modules are invoked.


2. Admission Module (admission.py)
Purpose: Manages student admission records.
Functionality:
New Admission: Allows entry of new student data including admission number, name, class, and roll number.
Student Details: Retrieves and displays student information by admission number or all students.
Edit Admission: Allows updating of existing student records.
Delete Admission: Deletes a student's record based on the admission number.
Classwise Student Details: Provides a visual histogram of student distribution across classes.


3. Sports Module (sports.py)
Purpose: Manages student sports activities and records.
Functionality:
Sports in School: Displays all available sports.
Add/Edit Student's Sport: Assigns a sport to a student or edits an existing sport assignment.
Return Students by Sport: Lists students participating in a particular sport.
Return Sport by Admission No.: Displays the sport a student is enrolled in.
All Students with Sports: Lists all students along with their assigned sports.
Graph of Sports vs Students: Generates a visual histogram of the number of students in each sport.


4. Fees Module (fees.py)
Purpose: Manages student fees payment status and records.
Functionality:
Check Fees Status: Checks if a student has paid the fees.
Fees Details (Annually): Displays the fee structure for each class.
Add Fees to Students: Marks a student's fees as paid.
Fees Record: Lists students who have paid or have not paid their fees.
Delete Fees Status: Removes the fee payment status for a student.


5. Connection Module (connection.py)
Purpose: Handles database connections and operations.
Functionality: Executes SQL queries to interact with the MySQL database for various CRUD operations (Create, Read, Update, Delete).


6. Clear Screen Utility (clear.py)
Purpose: Provides a utility to clear the console screen based on the operating system.


7. Display Connection Module (display_connection.py)
Purpose: Retrieves and displays results from the database.
Functionality: Executes queries and returns results, which are then displayed in the terminal.


This system is designed to be a comprehensive management tool for school administrators, allowing them to efficiently handle student admissions, track participation in sports, and manage fee payments.
