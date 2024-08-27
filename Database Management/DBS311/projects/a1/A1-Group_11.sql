--******************************************************************
-- Group #11
-- Name: Ekansh  ID: 167454214
-- Name: Soheila Fallah Mollamahmoud  ID: 142016229
-- Name: Kanisha  ID: 111877221 
-- Date: 2024-02-26
-- Purpose: Assignment 1 - DBS311NAA
-- All the content other than your sql code should be put in comment block.
-- Include your output in a comment block following with your sql code.
-- Remember add ; in the end of your statement for each question.
--******************************************************************

/*******************************************************************
-- Q1 Solution: 
-- Retrieves employees hired before June 2016 and after February 2016, sorted by hire date and employee ID.
-- This query fetches employee details such as ID, first name, last name, and hire date.
-- It filters employees who were hired before the first employee hired in June 2016 but two months after the last employee hired in February 2016.
-- Results are ordered by hire date and employee ID.
*******************************************************************/

PROMPT ********************************************
PROMPT Q1: 
SELECT EMPLOYEE_ID, FIRST_NAME, LAST_NAME, HIRE_DATE
FROM EMPLOYEES 
WHERE HIRE_DATE < (
    SELECT MIN(HIRE_DATE)
    FROM EMPLOYEES
    WHERE EXTRACT(MONTH FROM HIRE_DATE) = 06 AND EXTRACT(YEAR FROM HIRE_DATE) = 2016
) 
AND HIRE_DATE > (
    SELECT ADD_MONTHS(MAX(HIRE_DATE), 2) -- adding 2 months to  last employee hired in February 2016
    FROM EMPLOYEES
    WHERE EXTRACT(MONTH FROM HIRE_DATE) = 02 AND EXTRACT(YEAR FROM HIRE_DATE) = 2016
)
ORDER BY HIRE_DATE, EMPLOYEE_ID;

--EMPLOYEE_ID FIRST_NAME LAST_NAME HIRE_DATE
------------- ---------- --------- ----------
--        97	Harriet	 Ferguson	24-APR-16
--        23	Jackson	 Coleman 	01-MAY-16
--        75	Imogen	 Boyd	    11-MAY-16
--        16	Alex	 Sanders    18-MAY-16
--         5    Nathan	 Cox        21-MAY-16
--        98	Amber	 Rose	    23-MAY-16
--        79	Esme	 Warren	    24-MAY-16
--
-- 7 rows selected. 

/*******************************************************************
-- Q2 Solution: 
-- Selects distinct country IDs and names for countries with more than one location, sorted by country ID.
-- This query retrieves unique country IDs and names for countries with multiple locations.
-- It ensures uniqueness by comparing location IDs and joins with the COUNTRIES table to fetch country names.
-- Results are ordered by country ID.
*******************************************************************/

PROMPT ********************************************
PROMPT Q2: 
SELECT DISTINCT T1.COUNTRY_ID as "Country ID", C.COUNTRY_NAME as "Country Name"
FROM LOCATIONS T1 JOIN LOCATIONS T2 
ON T1.COUNTRY_ID = T2.COUNTRY_ID 
AND T1.LOCATION_ID <> T2.LOCATION_ID
INNER JOIN COUNTRIES C ON C.COUNTRY_ID = T1.COUNTRY_ID
ORDER BY T1.COUNTRY_ID;

-- Co Country Name                            
-- -- ----------------------------------------
-- CA Canada                                  
-- CH Switzerland                             
-- IT Italy                                   
-- JP Japan                                   
-- UK United Kingdom                          
-- US United States of America                
--
-- 6 rows selected. 

/*
In Q2 The idea is to join the locations table to itself on the 
country ID, ensuring the joined rows have different location IDs, 
which implies more than one location in the country. Then, we 
use the DISTINCT keyword to get unique country IDs and names.
*/

/*******************************************************************
-- Q3 Solution: 
-- Selects distinct country IDs and names for countries with only one location, sorted by country ID.
-- This query retrieves unique country IDs and names for countries with a single location.
-- It utilizes the MINUS set operator to find countries with unique locations and joins with the COUNTRIES table to fetch country names.
-- Results are ordered by country ID.
*******************************************************************/

PROMPT ********************************************
PROMPT Q3: 
SELECT C.COUNTRY_ID AS "Country ID", C.COUNTRY_NAME as "Country Name"
FROM 
    (
        SELECT DISTINCT  T1.COUNTRY_ID
        FROM LOCATIONS T1 JOIN LOCATIONS T2
        ON T1.COUNTRY_ID = T2.COUNTRY_ID -- ALL THE REPEATING COUNTRY_ID
        
        MINUS 
        
        SELECT DISTINCT T1.COUNTRY_ID
        FROM LOCATIONS T1 JOIN LOCATIONS T2
        ON T1.COUNTRY_ID = T2.COUNTRY_ID 
        AND T1.LOCATION_ID <>  T2.LOCATION_ID -- ONLY REPEATING COUNTRY_IDS
    ) t
JOIN COUNTRIES C 
ON t.COUNTRY_ID = C.COUNTRY_ID
ORDER BY C.COUNTRY_ID;


--Country ID Country Name
------------- -------------
--AU	Australia
--BR	Brazil
--CN	China
--DE	Germany
--IN	India
--MX	Mexico
--NL	Netherlands
--SG	Singapore

/*******************************************************************
-- Q4 Solution:
-- Displays customers with multiple orders in one month in 2017, showing the customer ID, month, and order count.
-- Query to display customers with multiple orders in one month in 2017
-- This query retrieves information about customers who have placed multiple orders within a single month in the year 2017.
*******************************************************************/

PROMPT ********************************************
PROMPT Q4: 
SELECT 
    customer_id AS "Customer ID", 
    TO_CHAR(order_date, 'MM') AS "Month", 
    COUNT(*) AS "Number of orders"
FROM 
    orders
WHERE 
    EXTRACT(YEAR FROM order_date) = 2017
GROUP BY 
    customer_id, TO_CHAR(order_date, 'MM')
HAVING 
    COUNT(*) > 1
ORDER BY 
    TO_CHAR(order_date, 'MM'), customer_id;
    
--Customer ID   Month    Number of orders
------------- ---------- ----------------
--       48	        03	                2
--        5 	    04	                2

/*******************************************************************
-- Q5 Solution: 
-- Displays customers who purchased products with IDs 20 and 95, showing the customer ID and name.
-- This query retrieves customers who purchased specific products with IDs 20 and 95.
-- It fetches customer details such as ID and name from the CUSTOMERS table and filters by the specified product IDs.
-- Results include customer ID and name.
*******************************************************************/

PROMPT ********************************************
PROMPT Q5: 
SELECT C.CUSTOMER_ID "CUSTOMER ID", C.NAME "NAME"
FROM CUSTOMERS C 
INNER JOIN ORDERS O ON C.CUSTOMER_ID = O.CUSTOMER_ID
WHERE ORDER_ID IN (20, 95);

--CUSTOMER ID   NAME
-----------     -------
--      20	    Dollar General
--      45	    CenturyLink

/*******************************************************************
-- Q6 Solution: 
-- Displays employee IDs and the number of orders for employees with order counts above the average.
-- This query fetches employee IDs and the count of orders they processed.
-- It filters out employees whose order count exceeds the average order count among all salespersons.
-- Results are ordered by employee ID.
*******************************************************************/

PROMPT ********************************************
PROMPT Q6: 
SELECT E.EMPLOYEE_ID AS "Employee ID", COUNT(O.ORDER_ID) AS "Number of Orders"
FROM EMPLOYEES E
JOIN ORDERS O ON E.EMPLOYEE_ID = O.SALESMAN_ID
GROUP BY E.EMPLOYEE_ID
HAVING COUNT(O.ORDER_ID) > (
    SELECT AVG(ORDER_COUNT)
    FROM (
        SELECT COUNT(ORDER_ID) AS ORDER_COUNT
        FROM ORDERS
        WHERE SALESMAN_ID IS NOT NULL
        GROUP BY SALESMAN_ID
    ) AVG_ORDERS
)
ORDER BY E.EMPLOYEE_ID;

--EMPLOYEE_ID Number of Orders
----------- ----------------
--         55               10
--         62               13
--         64               12

/*******************************************************************
-- Q7 solution:
-- This query retrieves aggregated data for each month in the year 2017.
-- It selects the month number and month name using TO_CHAR function, along with the count of orders and the sum of quantities.
-- The data is joined between the ORDERS and ORDER_ITEMS tables based on the ORDER_ID.
-- It filters data for the year 2017.
-- The results are grouped by month number and month name.
-- The results are sorted by month number.
*******************************************************************/

PROMPT ********************************************
PROMPT Q7: 
SELECT 
    TO_CHAR(ORDER_DATE,'MM') AS "Month Number",
    TO_CHAR(ORDER_DATE,'Month') AS "MONTH",
    COUNT(*) AS "Total Number of customers",
    SUM(OI.QUANTITY) AS "Sales Amount"
FROM 
    ORDERS O 
JOIN 
    ORDER_ITEMS OI ON O.ORDER_ID = OI.ORDER_ID
WHERE 
    EXTRACT(YEAR FROM ORDER_DATE) = 2017
GROUP BY 
    TO_CHAR(ORDER_DATE,'MM'), TO_CHAR(ORDER_DATE,'Month')
ORDER BY 
    "Month Number";

--Month Number Month Total Number of customers Sales Amount
-------------- ----- ------------------------- ------------
-- 01	January  	31	2857
-- 02	February 	85	7915
-- 03	March    	25	2032
-- 04	April    	13	1030
-- 05	May      	26	2311
-- 06	June     	7	820
-- 08	August   	38	3217
-- 09	September	25	2099
-- 10	October  	22	2143
-- 11	November 	2	245

/*******************************************************************
-- Q8 solution
-- This query calculates the average sales amount per month for orders placed in the year 2017.
-- It selects the month number and month name using TO_CHAR function, along with rounding the average quantity to two decimal places.
-- The data is joined between the ORDERS and ORDER_ITEMS tables based on the ORDER_ID.
-- It filters data for the year 2017 and groups the results by month number and month name.
-- The HAVING clause ensures that only months with an average quantity greater than the overall average quantity are included.
-- The results are sorted by month number.
*******************************************************************/

PROMPT ********************************************
PROMPT Q8: 
SELECT 
    TO_CHAR(ORDER_DATE,'MM') AS "Month Number",
    TO_CHAR(ORDER_DATE,'Month') AS "MONTH",
    ROUND(AVG(OI.QUANTITY),2) AS "Average Sales Amount"
FROM 
    ORDERS O 
JOIN 
    ORDER_ITEMS OI ON O.ORDER_ID = OI.ORDER_ID
WHERE 
    EXTRACT(YEAR FROM ORDER_DATE) = 2017
GROUP BY 
    TO_CHAR(ORDER_DATE,'MM'), TO_CHAR(ORDER_DATE,'Month')
HAVING 
    AVG(OI.QUANTITY) > (
        SELECT AVG(OI.QUANTITY)
        FROM ORDERS O 
        JOIN ORDER_ITEMS OI ON O.ORDER_ID = OI.ORDER_ID
    )
ORDER BY 
    "Month Number";

--Month Number Month Average Sales Amount
-------------- ----- --------------------
-- 01	January  	92.16
-- 02	February 	93.12
-- 06	June     	117.14
-- 10	October  	97.41
-- 11	November 	122.5


/*******************************************************************
-- Q9 solution
-- This query retrieves the first names of employees whose names start with the letter 'B' and are not present in the contacts list.
-- It utilizes the MINUS set operator to achieve the desired result, ensuring the names are in uppercase.
*******************************************************************/

PROMPT ********************************************
PROMPT Q9: 
SELECT 
    FIRST_NAME as "First Name"
FROM 
    EMPLOYEES
WHERE 
    UPPER(FIRST_NAME) LIKE ('B%')
MINUS
SELECT 
    FIRST_NAME 
FROM 
    CONTACTS
WHERE 
    UPPER(FIRST_NAME) LIKE ('B%');

--First Name
-------------
--Bella
--Blake

/*******************************************************************
-- Q10 solution
-- This query calculates various statistics related to employees and their orders.
*******************************************************************/

PROMPT ********************************************
PROMPT Q10: 
SELECT report
FROM (
    -- Count the number of employees with total order amount over average order amount
    SELECT 
        'The number of employees with total order amount over average order amount: ' || 
        (
            SELECT COUNT(ORDER_ID)
            FROM ORDERS
            WHERE ORDER_ID IN (
                -- Subquery to find the count of orders per employee that exceed the average order amount
                SELECT COUNT(ORDER_ID)
                FROM ORDERS
                -- Subquery to calculate the average order amount per employee
                HAVING COUNT(ORDER_ID) > (
                    SELECT AVG(COUNT(ORDER_ID))
                    FROM ORDERS
                    WHERE SALESMAN_ID IS NOT NULL
                    GROUP BY SALESMAN_ID 
                )
                GROUP BY SALESMAN_ID
            )
        ) AS report
    FROM DUAL

    UNION ALL

    -- Combine with the count of employees with total number of orders greater than 10
    SELECT 
        'The number of employees with total number of orders greater than 10: ' || 
        (
            SELECT COUNT(ORDER_ID)
            FROM ORDERS
            WHERE ORDER_ID IN (
                -- Subquery to find the count of orders per employee that exceed 10
                SELECT COUNT(ORDER_ID)
                FROM ORDERS
                WHERE SALESMAN_ID IS NOT NULL
                GROUP BY SALESMAN_ID
                HAVING COUNT(ORDER_ID) > 10
            ) 
        ) AS report
    FROM DUAL

    UNION ALL

    -- The number of employees with no order
    SELECT 
        'The number of employees with no order: ' || 
        (
            -- Subquery to count employees with no orders
            SELECT COUNT(*)
            FROM ORDERS 
            WHERE SALESMAN_ID IS NOT NULL
        ) AS report
    FROM DUAL
    
    UNION ALL
    
    -- Combine with the count of employees with orders
    SELECT 
        'The number of employees with orders: ' || 
        (
            -- Subquery to count employees with orders
            SELECT COUNT(*)
            FROM ORDERS 
            WHERE SALESMAN_ID IS NULL
        ) AS report
    FROM DUAL
) ordered_reports;

-- REPORT                                                                                                             
-- -------------------------------------------------------------------------------------------------------------------
-- The number of employees with total order amount over average order amount: 4
-- The number of employees with total number of orders greater than 10: 2
-- The number of employees with no order: 70
-- The number of employees with orders: 35












