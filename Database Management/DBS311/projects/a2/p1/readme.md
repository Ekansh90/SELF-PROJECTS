Online Shopping Cart Management System

1. Project Purpose
The purpose of this project is to develop an online shopping cart management system using C++ and Oracle Call Interface (OCI). 
The system allows customers to log in, place orders, check order statuses, and cancel orders. It interacts with an Oracle database to manage product information, customer details, and order processing.

2. Technologies and Libraries Used
C++: The core programming language used to develop the application.
Oracle Call Interface (OCI): Specifically, the project uses Oracle C++ Call Interface (OCCI), which provides a set of classes for connecting to and interacting with Oracle databases.
Oracle Database: The backend database system used to store and manage data related to customers, products, and orders.
Standard C++ Libraries: Including libraries for input/output streams (iostream), string manipulation (string, cstring), formatting (iomanip), and data conversion (sstream).


3. Main Components of the System
Main Menu:
Displays the primary options for the user, such as logging in or exiting the program.

Customer Login:
The customerLogin function verifies if a customer exists in the database by calling the find_customer stored procedure.

Customer Service Menu:
After successful login, the customer is presented with options to place an order, check an order's status, or cancel an order.

Placing an Order:
Customers can add products to their cart by entering the product ID.
The system verifies the existence of the product in the database using the findProduct function, which calls the find_product stored procedure.
After adding products, the order is processed by the checkout function, which calls the add_order and add_order_item stored procedures to record the order in the database.

Checking Order Status:
The displayOrderStatus function allows customers to check the status of their orders. It first verifies the order's validity using the customer_order procedure and then retrieves the order status using the display_order_status procedure.

Canceling an Order:
The cancelOrder function enables customers to cancel their orders. The function checks the order's validity and then attempts to cancel it using the cancel_order procedure.

4. Database Interaction
Stored Procedures:(1-procedures.sql) 
find_customer: Checks if a customer exists.
find_product: Retrieves product details like name and price.
add_order: Inserts a new order into the database.
add_order_item: Adds items to an existing order.
customer_order: Validates if an order belongs to the customer.
display_order_status: Retrieves the status of an order.
cancel_order: Cancels an order if it hasn't been shipped.


SQL Statements:
The project uses prepared statements to interact with the Oracle database. 
Each function utilizes a specific SQL statement to execute the required procedure, ensuring data integrity and security.


5. Error Handling
The project includes basic error handling using try-catch blocks to catch and display SQL exceptions (SQLException). 
This ensures that any issues during database interaction are captured and appropriately handled.


6. Environment and Connection Management
Environment Creation and Termination:
The createEnvironement and teminateEnvironement functions manage the Oracle environment, which is necessary for establishing a connection to the database.

Connection Management:
The openConnection and closeConnection functions handle opening and closing connections to the Oracle database, ensuring that resources are managed efficiently.

Conclusion
This project demonstrates the integration of C++ with Oracle databases through OCCI, allowing for a robust and scalable shopping cart management system. 
The system provides essential e-commerce functionality such as order placement, status tracking, and cancellation, all while maintaining data integrity 
and security through careful management of database interactions.



KEY CONCEPTS USED FOR CREATING PROCEDURES :

1. Input and Output Parameters
Input Parameters (IN):
These parameters are used to pass values into a procedure or function. They act as inputs to the block of code, and their values cannot be modified within the procedure or function.
Example Use: Suppose you want to pass a customer ID to a procedure to retrieve details about that customer. The customer ID would be passed as an input parameter.


Output Parameters (OUT):
These parameters are used to return values from a procedure or function. Unlike input parameters, the procedure or function can modify and set the value of an output parameter, which can then be accessed by the calling environment.
Example Use: If you want to determine whether a specific product is in stock and return that information, you would use an output parameter to return the stock status.

2. Conditional Statements
Conditional Statements (IF-THEN-ELSE):
Conditional statements in PL/SQL are used to execute certain parts of the code based on specific conditions.
IF-THEN: Executes a block of code if a specified condition is true.
IF-THEN-ELSE: Provides an alternative block of code that runs if the condition is false.
ELSIF: Allows checking multiple conditions in sequence, where the first condition that evaluates to true will trigger its corresponding code block.
Use Case: Conditional statements are useful when you need to perform different actions based on varying conditions, such as applying a discount during a particular time of year or checking whether an item is available in stock.

3. Using and Creating Functions

Creating Functions:
A function in PL/SQL is a reusable block of code that returns a single value. Functions can accept parameters (input, output, or both) and must return a value of a specific data type.
Functions are similar to procedures but are typically used when you need to compute and return a value, such as calculating a discount or generating a unique order ID.

Using Functions:
Once a function is created, it can be invoked in SQL statements, PL/SQL blocks, or other functions and procedures. Functions are often used to encapsulate and reuse logic that needs to be applied consistently across multiple parts of an application.
Example Use: A function might be used to calculate the total price of an order with taxes applied, and this function could be called whenever that calculation is needed.

These concepts help structure and control the flow of your PL/SQL programs, allowing for flexible and maintainable code that can interact with the database efficiently.
