------------------------ 1.A MENU INSERTION

INSERT ALL 
  INTO MENU(menuID,menu_type,rest_id) VALUES(1,'Breakfast',2091)
  INTO MENU(menuID,menu_type,rest_id) VALUES(2,'Lunch',2091)
  INTO MENU(menuID,menu_type,rest_id) VALUES(3,'Snacks',2091)
  INTO MENU(menuID,menu_type,rest_id) VALUES(4,'Dinner',2091)
  SELECT * FROM DUAL;
  
------------------------ 2.A MENU_CONTENT INSERTION 
INSERT ALL 
  INTO MENU_CONTENT(MENUID,ITEM_NAME,Price) VALUES(1,'Eggs and Ham',2.85)
  INTO MENU_CONTENT(MENUID,ITEM_NAME,Price) VALUES(1,'Eggs Sunny Side Up',2.32)
  INTO MENU_CONTENT(MENUID,ITEM_NAME,Price) VALUES(1,'French Toast',3.85)
  INTO MENU_CONTENT(MENUID,ITEM_NAME,Price) VALUES(1,'Grilled Cheese Sandwich',8.8)
  INTO MENU_CONTENT(MENUID,ITEM_NAME,Price) VALUES(1,'Chicken Club Sandwich',12.54)
  INTO MENU_CONTENT(MENUID,ITEM_NAME,Price) VALUES(1,'BLT',4.34)
  INTO MENU_CONTENT(MENUID,ITEM_NAME,Price) VALUES(1,'Hot Chocolate',1.85)
  INTO MENU_CONTENT(MENUID,ITEM_NAME,Price) VALUES(1,'Mocha Coffee',2.55)
  INTO MENU_CONTENT(MENUID,ITEM_NAME,Price) VALUES(1,'Orange Juice',3.25)
  INTO MENU_CONTENT(MENUID,ITEM_NAME,Price) VALUES(1,'Lemonade',1222.85)
  SELECT * FROM DUAL;
  
INSERT ALL
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(2, 'Tomato Soup',6.55)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(2, 'Chicken Broth Soup', 12.65)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(2, 'Hot and Sour Soup', 5.60)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(2, 'Ariabata Pasta', 16.55)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(2, 'Beef Bolgenese Pasta', 6.55)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(2, 'Macaroni and Cheese', 2.50)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(2, 'Noodles in stir-fry sauce', 19.35)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(2, 'Pork Wonton Soup', 21.65)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(2, 'Pork Ramen', 25.56)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(2, 'Chicken Ramen', 6.55)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(2, 'Lamb Curry', 16.55)
SELECT* FROM DUAL;
  
INSERT ALL
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(3, 'Chicken Shawarma', 12.85)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(3, 'Club Sandwiches', 22.25)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(3, 'Stir fry dumplings', 27.45)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(3, 'Canadian Pizza', 10.85)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(3, 'Pizza Margharita', 13.35)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(3, 'Cheeseburger', 14.55)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(3, 'Veggie Overload Pizza', 20.85)
INTO MENU_CONTENT(MENUID, ITEM_NAME,Price) VALUES(3, 'Hot Dogs', 5.95)
SELECT* FROM DUAL;

INSERT ALL
INTO MENU_CONTENT(MENUID, ITEM_NAME, Price) VALUES(4, 'Chinese Hotpot', 32.85)
INTO MENU_CONTENT(MENUID, ITEM_NAME, Price) VALUES(4, 'Fried Chicken', 25.25)
INTO MENU_CONTENT(MENUID, ITEM_NAME, Price) VALUES(4, 'Kimchi Fried Rice', 29.55)
INTO MENU_CONTENT(MENUID, ITEM_NAME, Price) VALUES(4, 'Shrimp Fried Rice', 28.55)
INTO MENU_CONTENT(MENUID, ITEM_NAME, Price) VALUES(4, 'Chicken Alfredo', 23.55)
INTO MENU_CONTENT(MENUID, ITEM_NAME, Price) VALUES(4, 'Nashville Chicken ', 27.55)
INTO MENU_CONTENT(MENUID, ITEM_NAME, Price) VALUES(4, 'Red Wine', 38.55)
INTO MENU_CONTENT(MENUID, ITEM_NAME, Price) VALUES(4, 'White Wine', 38.55)
INTO MENU_CONTENT(MENUID, ITEM_NAME, Price) VALUES(4, 'Cheescake', 19.55)
INTO MENU_CONTENT(MENUID, ITEM_NAME, Price) VALUES(4, 'Chocolate Pastries', 20.55)
INTO MENU_CONTENT(MENUID, ITEM_NAME, Price) VALUES(4, 'Pinapple Pastries', 20.55)
SELECT* FROM DUAL;


------------------------ 3.A INVENTORY INSERTION 
INSERT ALL
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5051, 'Lettuce', 'YES', 2091,5)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5052, 'ONIONS', 'YES', 2091, 10)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5053, 'TOMATOES', 'NO', 2091, 10)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5054, 'GREEN PEPEPRS', 'YES', 2091, 12)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5055, 'LAMB', 'YES', 2091,5)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5056, 'CHICKEN', 'YES', 2091,20)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5057, 'NOODLES', 'NO', 2091,0)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5058, 'HOLLAINDAISE SAUCE', 'NO', 2091,0)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5059, 'TOMATO KETCHUP', 'YES', 2091,15)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5060, 'MUSTARD', 'NO', 2091,0)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5061, 'MAYONAISE', 'YES', 2091,7)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5062, 'RED WINE', 'YES', 2091,3)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5063, 'PLATES', 'NO', 2091,0)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5064, 'CUTLERY', 'NO', 2091,0)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5065, 'BUTTER', 'YES', 2091,12)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5066, 'CHEESE', 'YES', 2091,10)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5067, 'CABBAGES', 'YES', 2091,5)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5068, 'BROCOLLI', 'NO', 2091, 0)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5069, 'CHIVCES', 'YES', 2091,2)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5070, 'SESAME OIL', 'NO', 2091,0)
INTO INVENTORY(stock_ID, INVENTORY_ITEMS, INVENTORY_NEEDED, rest_id, bags_needed) VALUES(5071, 'OLIVE OIL', 'YES', 2091,3)
SELECT* FROM DUAL;

------------------------ 4.A INVENTORY INSERTION 
INSERT ALL 
INTO FINANCES(finance_ID,money_spent_on_supplies,budget,profit,loss) VALUES(8081,2500,5000,50,0)
  INTO FINANCES(finance_ID,money_spent_on_supplies,budget,profit,loss) VALUES(8082,9500,7000,0,35)
  INTO FINANCES(finance_ID,money_spent_on_supplies,budget,profit,loss) VALUES(8083,4500,5000,10,0)
  SELECT * FROM DUAL;

INSERT ALL 
INTO FINANCES(finance_ID,money_spent_on_supplies,budget,profit,loss,REST_ID) VALUES(8084,700,1000,0,42,2092)
  INTO FINANCES(finance_ID,money_spent_on_supplies,budget,profit,loss,REST_ID) VALUES(8085,9500,15000,63,0,2092)
  INTO FINANCES(finance_ID,money_spent_on_supplies,budget,profit,loss,REST_ID) VALUES(8086,2500,10000,25,0,2092)
  SELECT * FROM DUAL;



INSERT ALL 
INTO FINANCES(finance_ID,money_spent_on_supplies,budget,profit,loss,REST_ID) VALUES(8087,1500,15000,100,0,2093)
  INTO FINANCES(finance_ID,money_spent_on_supplies,budget,profit,loss,REST_ID) VALUES(8088,20000,7000,35,0,2093)
  INTO FINANCES(finance_ID,money_spent_on_supplies,budget,profit,loss,REST_ID) VALUES(8089,14500,20000,0,27,2093)
  SELECT * FROM DUAL;


------------------------ 5.A ROLE INSERTION 
INSERT ALL
INTO ROLE(role_id, role_type, min_days_for_promo,EMP_WAGE) VALUES(550, 'Trainee', 0,15.75)
INTO ROLE(role_id, role_type, min_days_for_promo,EMP_WAGE) VALUES(600, 'Grill', 15,20.50)
INTO ROLE(role_id, role_type, min_days_for_promo,EMP_WAGE) VALUES(650, 'Prep Line', 20,24)
INTO ROLE(role_id, role_type, min_days_for_promo,EMP_WAGE) VALUES(700, 'Morning Crew', 25,30.10)
INTO ROLE(role_id, role_type, min_days_for_promo,EMP_WAGE) VALUES(720, 'Night Crew', 25,40.45)
INTO ROLE(role_id, role_type, min_days_for_promo,EMP_WAGE) VALUES(750, 'Back of House', 30,50.50)
INTO ROLE(role_id, role_type, min_days_for_promo,EMP_WAGE) VALUES(1200, 'Head Chef', 65 , 60.225)
INTO ROLE(role_id, role_type, min_days_for_promo,EMP_WAGE) VALUES(1650, 'Pastry Chef', 70 , 62.35)
INTO ROLE(role_id, role_type, min_days_for_promo,EMP_WAGE) VALUES(4800, 'Executive Assistant', 90 , 65.70)
INTO ROLE(role_id, role_type, min_days_for_promo,EMP_WAGE) VALUES(3000, 'Manager', 180 ,72.75)
SELECT* FROM DUAL;

------------------------ 6.A SCHEDULE INSERTION 
INSERT ALL
  INTO SCHEDULE (schedule_id,shift_type,shift_starts,shift_ends) VALUES(1,'Morning','06:00 AM','12:00 PM')
  INTO SCHEDULE (schedule_id,shift_type,shift_starts,shift_ends) VALUES(2,'AFTERNOON','12:30 AM','18:00 PM')
  INTO SCHEDULE (schedule_id,shift_type,shift_starts,shift_ends) VALUES(3,'NIGHT','18:30 PM','00:00 AM')
  INTO SCHEDULE (schedule_id,shift_type,shift_starts,shift_ends) VALUES(4,'OverNight','00:00 PM','05:00 AM')
  SELECT * FROM DUAL;



------------------------ 7.A-MAIN EMPLOYEES INSERTION 
INSERT ALL
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110110, 700,3 , 'Jonathan', 'Majors', '321 Wilcox Street', '203 828 1011')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110112, 550,1 , 'Sarah', 'Sadie', '72 Green Park Drve', '431 618 4030')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110113, 750,4 , 'Emily', 'Paris', '15 Lawreel Drive', '269 873 4507')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110114, 4800,3 , 'Jessica', 'Thompson', '74 saint Parks street', '565 577 8195')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110115, 1200,2, 'Samantha', 'Ronic', 'Russaiana Park Road', '502 974 3907')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110116, 3000,4 , 'Jennifer ', 'Aniston', '26TH tall apartments', '957 826 2972')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110117, 700,1 , 'Elizabeth', 'Wellsely', 'Castlemore Road', '397 532 8676')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110118, 650,2 , 'Katherine', 'Hanh', '12 Sweet city park road', '529 858 7850')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110119, 550,1 , 'Christina', 'Callaghan', 'Missisauga Long Stree', '456 623 5316')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110121, 1650,4 , 'Maria', 'Oliver', 'Little Italy', '412 362 4488')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110122, 550,3 , 'Olivia', 'Mover', 'Jason Park Road', '720 082 8766')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110123, 1200,2 , 'Mary', 'Watson', 'hello campbell avenue', '442 222 7702')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110124, 1650,2 , 'Cassandra', 'Audittore', '16 street 6th', '199 251 9072')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110125, 550,4 , 'Sara', 'Shell', 'lesley beach drive', '555 932 9747')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110126, 700,1 , 'Livie', 'Shi', 'Long road apartments', '403 281 8266')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110127, 650,2 , 'Tiphanie', 'Tophie', 'Hallelujah city ', '544 562 8335')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110128, 550,4 , 'Christiano', 'Mbappe', 'Spaniard street avenue', '562 336 4618')
INTO EMPLOYEES(emp_id,role_id, schedule_id , emp_firstName, emp_lastName, emp_address, emp_contact) VALUES(110129, 650,1 , 'Reginaldo', 'Gaztambite', 'FINCH', '989 1970 959')
SELECT* FROM DUAL;

------------------------ 8.A-MAIN RESTERAUNT_BRANCH INSERTION 
INSERT ALL 
  INTO RESTERAUNT_BRANCH(rest_ID,rest_location,rest_stars) VALUES(2091,'Montreal',5)
  INTO RESTERAUNT_BRANCH(rest_ID,rest_location,rest_stars) VALUES(2092,'Downtown',3.5)
  INTO RESTERAUNT_BRANCH(rest_ID,rest_location,rest_stars) VALUES(2093,'Missisuaga',2.5) -- edit this value
  SELECT * FROM DUAL;



----------------------- 7.B-MAIN EMPLOYEES CONNECTION CONNECTS TO PK OF [SCHEDULE ,ROLE,RESTERAUNT_BRANCH]
ALTER TABLE EMPLOYEES 
add CONSTRAINT emp_schedule_fk 
    FOREIGN KEY(schedule_id)
    REFERENCES SCHEDULE(schedule_id);

ALTER TABLE EMPLOYEES 
add CONSTRAINT emp_role_fk 
    FOREIGN KEY(role_id)
    REFERENCES ROLE(role_id);
    
ALTER TABLE EMPLOYEES 
add CONSTRAINT emp_rest_fk 
    FOREIGN KEY(rest_id)
    REFERENCES RESTERAUNT_BRANCH(rest_id);
  

----------------------- 4.B FINANCES CONNECTION CONNECTS TO PK OF RESTERAUNT BRANCH
ALTER TABLE FINANCES 
add CONSTRAINT finances_fk 
    FOREIGN KEY(rest_id)
    REFERENCES RESTERAUNT_BRANCH(rest_id);
    
----------------------- 3.B INVENTORY CONNECTION CONNECTS TO PK OF RESTERAUNT BRANCH
ALTER TABLE INVENTORY 
add CONSTRAINT rest_stock_fk 
    FOREIGN KEY(rest_id)
    REFERENCES RESTERAUNT_BRANCH(rest_id);

----------------------- 2.B MENU_CONTENT CONNECTION  WITH MENU PK (1)
ALTER TABLE MENU_CONTENT 
add CONSTRAINT menu_cont_fk 
    FOREIGN KEY(MENUID)
    REFERENCES MENU(MENUID); 
    
----------------------- 1.B MENU CONNECTION (2)
ALTER TABLE MENU 
add CONSTRAINT rest_id_fk 
    FOREIGN KEY(rest_id)
    REFERENCES RESTERAUNT_BRANCH(rest_id);
  

    
/*
--TO RESTART AND REMOVE RELATIONSHIPS
-- Dropping tables in order , to not be restricted by relationships . Hence , dropiing child tables first.
    
    
DROP TABLE MENU_content ;
DROP TABLE MENU ;
DROP TABLE INVENTORY ;
DROP TABLE FINANCES;

DROP TABLE EMPLOYEES;
DROP TABLE SCHEDULE ;
DROP TABLE ROLE;
DROP TABLE RESTERAUNT_BRANCH;
    
*/
