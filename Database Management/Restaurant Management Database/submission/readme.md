Restaurant Management Database Project Overview
In this project, I designed and implemented a comprehensive database for managing a restaurant's operations. The database covers essential functionalities such as order processing, inventory management, employee management, and customer relationship management. Below is an elaboration on the structure and components of this database, along with the associated SQL scripts.

1. Database Structure
The database was designed with the following key tables:

Customers: Stores customer information, including contact details and preferences.
Employees: Manages employee data, including roles, shifts, and salaries.
Menu_Items: Contains details about the dishes offered, including pricing and ingredients.
Orders: Records customer orders, linking them to menu items and customer details.
Inventory: Tracks the ingredients and supplies, including their quantities and reorder levels.
Suppliers: Holds information about the suppliers who provide the ingredients.
Reservations: Manages table reservations, including customer details and reservation times.
Payments: Tracks payment details for orders, including payment method and status.

2. SQL Scripts and Operations
Insertion Script (insertionScript.sql): This script is responsible for inserting initial data into the database. It populates the tables with sample data, such as menu items, customer records, employee details, and inventory levels. The script is designed to ensure data integrity and consistency across the database.

Creation Script (creationScript.sql): This script contains the SQL commands required to create the database schema. It defines the tables, relationships, constraints, and indexes that structure the database. This script is fundamental to setting up the database from scratch.

Business Reports (BUSINESS_REPORTS.sql): This script creates various views to support business decision-making. Views are designed to provide insights into different aspects of the restaurant's operations, such as sales trends, inventory usage, and employee performance. These views allow different users (e.g., managers, chefs, and financial analysts) to access tailored reports.

3. Additional Features
User Roles and Permissions: Implemented user roles to ensure that employees have appropriate access levels. For example, chefs can update inventory levels, while managers can view sales reports.

Triggers and Stored Procedures: Added triggers for automatic inventory updates when an order is placed and stored procedures for complex operations like generating end-of-day sales reports.

This restaurant management database was designed to streamline operations, enhance data accessibility, and support informed decision-making. The use of structured SQL scripts for data insertion, table creation, and reporting ensures that the system is robust, scalable, and easy to maintain.
The diagram for set up relations( one-to-one, one-to-many, many-to-many ) between tables is attached below :



![image](https://github.com/user-attachments/assets/af05ff83-21f5-418e-9fe8-ce5012001a93)



