--******************************************************************
-- Group #11

--Name: Soheila Fallah Mollamahmoud  ID: 142016229
-- Name: Ekansh  ID: 167454214
-- Name: Kanisha  ID: 111877221
-- Date: 2024-03-27
-- Purpose: Assignment 2 - DBS311NAA

--******************************************************************


set serveroutput on ;
-------------------------1 

select * from products ;
/
    SELECT CUSTOMER_ID 
    FROM CUSTOMERS
    WHERE Customers.CUSTOMER_ID = 35 ;
/
CREATE OR REPLACE PROCEDURE find_customer( customer_id IN NUMBER, found OUT NUMBER)
AS 
    returnVal CUSTOMERS.CUSTOMER_ID%TYPE  ;
BEGIN 
    SELECT CUSTOMER_ID 
    INTO returnVal 
    FROM CUSTOMERS
    WHERE Customers.CUSTOMER_ID = find_customer.CUSTOMER_ID ;
    
   IF returnVal IS NOT NULL THEN
        found := 1;
        dbms_output.put_line('return :' || returnVal || 'found : ' || found );
    ELSE
        found := 0;
        dbms_output.put_line('return :' || returnVal || 'found : ' || found );

    END IF;

EXCEPTION 
    
    WHEN TOO_MANY_ROWS THEN 
        found := 0;
        dbms_output.put_line('MULTIPLE ROWS RETURNED FOR ID : ' || customer_id || 'TRY USING A CURSOR');
    
    WHEN NO_DATA_FOUND THEN 
        found := 0;
        dbms_output.put_line('DATA CANT BE FOUND FOR ID : ' || customer_id );
        
    WHEN OTHERS THEN 
        found := 0;
        dbms_output.put_line('ERROR');
        

    
END ; 

/

declare 
     cid CUSTOMERS.CUSTOMER_ID%TYPE := 21 ;
     found number := 0 ;
begin 
    find_customer(cid,found);
end ;

-------------------------2
/

SELECT * FROM PRODUCTS ;
SELECT * FROM PRODUCT_categories ;

SELECT P.PRODUCT_ID , P.PRODUCT_NAME , P.LIST_PRICE , P.CATEGORY_ID
FROM PRODUCTS P JOIN PRODUCT_CATEGORIES PC
ON P.CATEGORY_ID = PC.CATEGORY_ID
WHERE P.CATEGORY_ID IN (2,5)
ORDER BY P.CATEGORY_ID;


SELECT list_price -  (list_price* 10/100)  , category_id
        FROM products
        WHERE category_id IN (2, 5);
       -- AND product_id = 35 ;


/
CREATE OR REPLACE PROCEDURE find_product (
productId IN NUMBER, price OUT products.list_price%TYPE,
productName OUT products.product_name%TYPE)

AS
    IDFound PRODUCTS.PRODUCT_ID%TYPE ;
BEGIN

    
    -- CALCULATING DISCOUNT BASED ON MONTH
    IF TO_CHAR(SYSDATE,'MM') BETWEEN 11 AND 12 THEN  -- 10% DISCOUNT IF CURRENT MONTH IS 11 OR 12
    
        SELECT list_price -  (list_price* 10/100)
            INTO price
            FROM PRODUCTS 
            WHERE PRODUCT_ID =  find_product.productId
            AND CATEGORY_ID IN (2,5);
            
    ELSE -- NO DISCOUNT
    
        SELECT list_price
            INTO price
            FROM PRODUCTS 
            WHERE PRODUCT_ID =  find_product.productId ;
    
    END IF ;  
    
    
    -- storing id in tempVar and names 
    SELECT PRODUCT_ID , PRODUCT_NAME --, LIST_PRICE 
    INTO IDFound , productName -- , price -- into cannot be used with input (in) paramaters
    FROM PRODUCTS
    WHERE PRODUCT_ID =  find_product.productId;
    
    IF IDFound IS  NULL THEN 
        productName := NULL ;
        price := 0 ;
    END IF ;
    
    dbms_output.put_line('id: ' || IDFound || 'name: ' || productName || 'price: ' || price);

EXCEPTION

    WHEN TOO_MANY_ROWS THEN 
        productName := NULL ;
        price := 0 ;
        dbms_output.put_line('MULTIPLE ROWS RETURNED FOR ID : ' || productId || 'TRY USING A CURSOR');
    
    WHEN NO_DATA_FOUND THEN 
        productName := NULL ;
        price := 0 ;
        dbms_output.put_line('DATA CANT BE FOUND FOR ID : ' || productId );
        
    WHEN OTHERS THEN 
        productName := NULL ;
        price := 0 ;
        dbms_output.put_line('ERROR');
        

END ;
/
declare 
     Pid PRODUCTS.PRODUCT_ID%TYPE := 133 ;
     productName products.product_name%TYPE :=0 ;
     price products.list_price%TYPE:= 0;
     found number := 0 ;
begin 
    find_product(Pid,price,productName);
end ;

/


SAVEPOINT BEFORE_INSERT ;

CREATE TABLE TEMP_ORDERS AS
SELECT * FROM ORDERS ;

SELECT * FROM TEMP_ORDERS
ORDER BY ORDER_ID;

select max(order_id) + 1 
from orders ;

ROLLBACK  BEFORE_INSERT ;
/
-------------------------3

CREATE OR REPLACE PROCEDURE add_order (customer_id IN NUMBER, new_order_id OUT NUMBER)

AS
    
BEGIN
    -- CHECKING IF IT IS WORKING OR NOT FIRST
    new_order_id := generate_order_id() ;
    
    -- CALL FUNCTION HERE
    /*
    select max(order_id)+1  
    into new_order_id
    from orders ;
    */
    
    
    INSERT INTO ORDERS (ORDER_ID,CUSTOMER_ID,STATUS,SALESMAN_ID , ORDER_DATE)
    VALUES (new_order_id , customer_id , 'Shipped' , 56 , SYSDATE) ;

EXCEPTION 
    WHEN OTHERS THEN 
        dbms_output.put_line('ERROR');
    

END ;
/
SELECT * FROM ORDERS
WHERE CUSTOMER_ID = 44
ORDER BY ORDER_ID;

SELECT *
FROM ORDER_ITEMS
WHERE ORDER_ID = 110;
/
declare 
     customer_id NUMBER := 4 ;
     new_order_id number := 0 ;
begin 
    add_order(customer_id,new_order_id);
end ;

--3 b TODO FUNCTION
-- TODO : CHANGE TABLE NAMES AND PUT COMMITS
/
-- NO PARAMETERS NO BRACKETS
CREATE OR REPLACE FUNCTION generate_order_id
RETURN NUMBER 

AS
    return_order_id number ;
BEGIN
    select max(order_id)+1  
    into return_order_id
    from orders ;
    
    return return_order_id ;

END ;
/

-- oracle function
-- CHECK HOW CAN WE CALL IT IN ORACLE , CHECK SYNTAX , HOW TO USE TABLE




SAVEPOINT BEFORE_SEC_TABLE ;

CREATE TABLE TEMP_ORDER_ITEMS AS
SELECT * FROM ORDER_ITEMS ;


SELECT * FROM TEMP_ORDER_ITEMS ;

-----------------------4 
/
CREATE OR REPLACE PROCEDURE add_order_item (orderId IN order_items.order_id%type,
    itemId IN order_items.item_id%type, 
    productId IN order_items.product_id%type, 
    quantity IN order_items.quantity%type,
    price IN order_items.unit_price%type)
    
AS 
    

BEGIN 
        INSERT INTO ORDER_ITEMS (ORDER_ID , ITEM_ID , PRODUCT_ID , QUANTITY , UNIT_PRICE)
        VALUES ( orderId , itemId , productId , quantity , price );
    
EXCEPTION 
    WHEN OTHERS THEN 
        dbms_output.put_line('ERROR');

END  ;
/

----------------------- 5
set serveroutput on ;
SELECT * FROM ORDERS ;
WHERE CUSTOMER_ID = 21 ;
WHERE ORDER_ID = 105 ;
/
CREATE OR REPLACE PROCEDURE customer_order (customerId IN NUMBER, orderId IN OUT NUMBER)
AS

BEGIN

    -- orderId : IN OUT PARAMETER SO WE CAN STORE VALUE IN IT
    SELECT ORDER_ID 
        INTO orderId 
        FROM ORDERS
        WHERE ORDER_ID = orderId 
        AND CUSTOMER_ID = customerId ;
        
    dbms_output.put_line('DATA  FOUND FOR CUSTOMER_ID : ' || customerId || ' | AND ORDER_ID RETURNED WAS : ' || orderId  );
        
EXCEPTION 
    WHEN NO_DATA_FOUND THEN 
        orderId := 0 ;
        dbms_output.put_line('DATA CANT BE FOUND FOR CUSTOMER_ID : ' || customerId || ' | AND ORDER_ID RETURNED WAS : ' || orderId  );
        
    WHEN OTHERS THEN 
        orderId := 0 ;
        dbms_output.put_line('ERROR');
    
    
END ;
/

declare 
     customer_id NUMBER := 44 ;
     order_id number := 105 ;
begin 
    customer_order(customer_id,order_id);
    dbms_output.put_line('orderId: ' || order_id);
    
end ;

/

set serveroutput on ;
------------------- 6

CREATE OR REPLACE PROCEDURE display_order_status(orderId IN NUMBER, status OUT orders.status%type)
AS

BEGIN
     SELECT LOWER(ORDERS.STATUS)
        INTO status 
        FROM ORDERS
        WHERE ORDER_ID = orderId ;
        
    dbms_output.put_line('DATA  STATUS FOR CUSTOMER_ID : ' || status || ',, AND ORDER_ID RETURNED WAS : ' || orderId  );
        
EXCEPTION 
    WHEN NO_DATA_FOUND THEN 
        status := NULL ;
        dbms_output.put_line('DATA STATUS CANT BE FOUND FOR CUSTOMER_ID : ' || status || '  AND ORDER_ID RETURNED WAS : ' || orderId  );
        
    WHEN OTHERS THEN 
        status := NULL ;
        dbms_output.put_line('ERROR');


END ;


/

declare 
     order_id NUMBER := 21; 
     status orders.status%type := '' ;
begin 
    display_order_status(order_id,status);
end ;

/
------------------------- 7
select * from orders ;
where order_id = 21;

/
-- VALUE CAN BE STORED FROM SELECT ONLY FOR OUPTUT PARAMETERS
CREATE OR REPLACE PROCEDURE cancel_order(orderId IN NUMBER, cancelStatus OUT NUMBER)
AS 
    orderStatus ORDERS.STATUS%TYPE  ;

BEGIN 
    SELECT LOWER(ORDERS.STATUS)
        INTO orderStatus 
        FROM ORDERS
        WHERE ORDER_ID = orderId ;
        
    IF orderStatus = LOWER('Canceled') then 
        cancelStatus := 1 ;
    ELSIF orderStatus = LOWER('Shipped') then 
        cancelStatus := 2 ;
    ELSE
        -- if pending
        cancelStatus := 3 ;
        update orders
        set status = 'Canceled'
        where ORDER_ID = orderId ;
    END IF ;
        
    dbms_output.put_line('DATA  STATUS FOR CUSTOMER_ID : ' || cancelStatus || ',, AND ORDER_ID RETURNED WAS : ' || orderId  );
    
EXCEPTION 
    WHEN NO_DATA_FOUND THEN 
        cancelStatus := 0 ;
        dbms_output.put_line('DATA STATUS CANT BE FOUND FOR CUSTOMER_ID : ' || cancelStatus || '  AND ORDER_ID RETURNED WAS : ' || orderId  );
        
    WHEN OTHERS THEN 
        cancelStatus := NULL ;
        dbms_output.put_line('ERROR');


END ;
/
///////////////// 
-- 1 . takout messages
-- 2. change temp tables
-- 3. add commits
-- 4 . make functions

declare 
     order_id NUMBER := 21;
     status Number := 0;
begin 
    cancel_order(order_id,status);
end ;
