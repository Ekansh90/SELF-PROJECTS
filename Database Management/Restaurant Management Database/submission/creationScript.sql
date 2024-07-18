-- MENU 
CREATE TABLE MENU
(
    menuId INT PRIMARY KEY,
    menu_type VARCHAR(25) ,
    rest_id INT 
);

CREATE TABLE MENU_CONTENT
(
    MENUID INT ,
    ITEM_NAME VARCHAR(25),
    Price DECIMAL(6,2)
);

CREATE TABLE INVENTORY
(
	stock_id INT PRIMARY KEY,
	inventory_items varchar(25),
	inventory_needed varchar(25),
    bags_needed int DEFAULT 0 ,
	rest_id INT
);

CREATE TABLE FINANCES 
(
	finance_id INT PRIMARY KEY ,
	money_spent_on_supplies DECIMAL(10,2),-- (supplies_expenditure) int
	budget DECIMAL(10,2) DEFAULT 0,
	profit DECIMAL(10,2) DEFAULT 0,
	loss DECIMAL(10,2) DEFAULT 0,
	rest_id INT DEFAULT 2091
) ;

CREATE TABLE ROLE
(
	role_id INT PRIMARY KEY  ,
	role_type varchar(25) ,
	min_days_for_promo INT,
    emp_wage DECIMAL(10,2) DEFAULT 15.75,
	emp_id INT DEFAULT 2091
) ;

CREATE TABLE SCHEDULE
(
	schedule_id INT PRIMARY KEY  ,
	shift_type varchar(25) ,
	shift_starts varchar(25) ,
	shift_ends varchar(25) 
);

CREATE TABLE EMPLOYEES 
(	
	emp_id int PRIMARY KEY,
    emp_firstName varchar(25) ,
    emp_lastName varchar(25) ,
	emp_address varchar(25) ,
    emp_contact varchar(25) ,
	role_id INT DEFAULT 550,
	schedule_id INT DEFAULT 2 ,
    rest_id INT DEFAULT 2091
);



CREATE TABLE RESTERAUNT_BRANCH
(
	rest_id INT PRIMARY KEY ,
	rest_location VARCHAR(25),
	rest_stars INT
);
