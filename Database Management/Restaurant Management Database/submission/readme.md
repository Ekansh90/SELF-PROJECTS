1)The sql files in this folder perform create , read ,update and delete operations on the following database diagram below .


2)The sql file for the same database below is in creationScript.sql 

3)Additional views have been created for different users to check different business reports .


![image](https://github.com/user-attachments/assets/af05ff83-21f5-418e-9fe8-ce5012001a93)


DATA DICTIONARIES FOR RESTAURANT MANAGEMENT DATABASE :
( The details are subject to change when we are actually inserting the values in the tables for these in SQL )

MENU
Column	Data Type	Size, Precision	Default	PK/FK	Required	Range	Sample Data	Notes
menuID	INT	10		PK	Y	1-9999	3134	Cannot be negative
menu_timings	String	25			Y		“Morning”	
restID	INT	10		FK	Y	1-999999	17892	Cannot be negative and same as menuID

MENU_CONTENT
Column	Data Type	Size, Precision	Default	PK/FK	Required	Range	Sample Data	Notes
menuID	INT	10		PK , FK	Y	1-9999	3134	Cannot be negative
menu_content	String	25			Y		“Pasta” , “Pizza” , “Scrambled eggs “	


INVENTORY
Column	Data Type	Size, Precision	Default	PK/FK	Required	Range	Sample Data	Notes
stockID	NUMBER	10		PK	Y	1-9999	1234	Cannot be negative
Inventory_items	String	25			Y		“Onions”	Items we already have .
Inventory_needed	String	25			Y		“Tomatoes”	Items that are needed .
restID	INT	10		FK	Y	1-999999	17892	Cannot be negative and same as menuID




FINANCES 
Column	Data Type	Size, Precision	Default	PK/FK	Required	Range	Sample Data	Notes
financeID	INT	10		PK	Y	1-9999	1234	Cannot be negative
money_spent_on_supplies	NUMBER	9,2			Y	200-99999	456,21	Cannot be negative
budget	NUMBER	9,2			Y	200-99999	10000	Cannot be negative
money_earned	NUMBER	9,2			Y	200-99999	20000	Cannot be negative
Profit(%)	INT	10	0.00		NULLABLE	0-99999	0-100	Cannot be negative
Loss(%)	INT	10	0.00		NULLABLE	0-99999	0-100	Cannot be negative
restID	INT	10		FK	Y	1-999999	17892	Cannot be negative and same asmenuID

CUSTOMERS
Column	Data Type	Size, Precision	Default	PK/FK	Required	Range	Sample Data	Notes
custID	INT	4		PK	Y	1-9999	1234	
cust_FirstName	VARCHAR	25			Y		“Haythem”	
cust_LastName	VARCHAR	25			Y		“Mark”	
cust_contact	INT	4			Y	2000000000-9999999999	9055551212	
cust_feedback	NUMBER	1,1	0		N	1 TO 10	5.5	


RESTAURANTS
Column	Data Type	Size, Precision	Default	PK/FK	Required	Range	Sample Data	Notes
restID	INT	4		PK	Y	1-9999	1234	Cannot be negative
rest_name	VARCHAR	25			Y		“Haythem”	
rest_location	VARCHAR	25			Y		“Mark”	
rest_stars	NUMBER	1,1	3		Y	0 - 5	4.5	Ratings received by restaurants ( out of 5 ) .
custId	INT	10		FK	Y	1-9999	1234	
menuID	INT	10		FK	Y	1-9999	3134	Cannot be negative
stockID	NUMBER	10		FK	Y	1-9999	1234	Cannot be negative
financeID	INT	10		FK	Y	1-9999	1234	Cannot be negative

EMPLOYEES 
Column	Data Type	Size, Precision	Default	PK/FK	Required	Range	Sample Data	Notes
employeeID	INT	4		PK	Y	1-9999	1234	
emp_FirstName	VARCHAR	25			Y		“Haythem”	
emp_LastName	VARCHAR	25			Y		“Mark”	
emp_address	VARCHAR	25			Y		“Lawrell Drive”	
emp_contact	STRING	4			Y	2000000000-9999999999	9055551212	
emp_wages	NUMBER	9,1	15		Y	15-500	15.75	Wages an employee can earn per hour .
roleID	INT	4		FK	Y	1-10	2	Each Id is linked with a role type.
Schedule_id	INT	4		FK	Y	1-4	1234	Each schedule ID is linked with a shift_type .
								


ROLES
Column	Data Type	Size, Precision	Default	PK/FK	Required	Range	Sample Data	Notes
roleID	INT	4		PK	Y	1-10	2	Each Id is linked with a role type.
role_type	VARCHAR	25	“Trainee” or “Crew”		Y	“Head Chef” , “Trainee” , “Crew” , “Manger”
( more may be added later)	“Manger”	Multiple roles in the hierarchy in a restaurant.
min_days_for_promo	INT	5	25		Y	10-60	32	Number of days , when an employee can apply for promotion .
hours_worked	NUMBER	2,1			Nullable		5	
employeeID	INT	4		FK	Y	2000000000-9999999999	9055551212	

SCHEDULE
Column	Data Type	Size, Precision	Default	PK/FK	Required	Range	Sample Data	Notes
Schedule_ID	INT	4		PK	Y	1-4	1234	Each schedule ID is linked with a shift_type .
shift_type	VARCHAR	25			Y	“MORNING ,
“AFTERNOON” “EVENING” ,
“NIGHT”
	Afternoon	Can be one of the 4 types of shift
shift_starting	NUMBER	2,2			Y		16.30	
shift_ending	NUMBER	2,2			Y		21.30	
								
employeeID	INT	4		FK	Y	2000000000-9999999999	9055551212	



