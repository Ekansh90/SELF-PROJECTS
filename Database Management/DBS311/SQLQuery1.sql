--------------------------------------------------------------------------------------
-- Name	       : OT (Oracle Tutorial) Sample Database
-- Link	       : http://www.oracletutorial.com/oracle-sample-database/
-- Version     : 1.0
-- Last Updated: July-28-2017
-- Copyright   : Copyright © 2017 by www.oracletutorial.com. All Rights Reserved.
-- Notice      : Use this sample database for the educational purpose only.
--               Credit the site oracletutorial.com explitly in your materials that
--               use this sample database.
--------------------------------------------------------------------------------------
-- schema.sql
-- data.sql
-- drop_tables.sql

---------------------------------------------------------------------------
-- execute the following statements to create tables
---------------------------------------------------------------------------
-- regions
CREATE TABLE regions
  (
    region_id decimal PRIMARY KEY,
    region_name VARCHAR( 50 ) NOT NULL
  );
-- countries table
CREATE TABLE countries
  (
    country_id   CHAR( 2 ) PRIMARY KEY  ,
    country_name VARCHAR( 40 ) NOT NULL,
    region_id    decimal                 , -- fk
    CONSTRAINT fk_countries_regions FOREIGN KEY( region_id )
      REFERENCES regions( region_id ) 
      ON DELETE CASCADE
  );

-- location
CREATE TABLE locations
  (
    location_id decimal( 12, 0 ) PRIMARY KEY       ,
    address     VARCHAR( 255 ) NOT NULL,
    postal_code VARCHAR( 20 )          ,
    city        VARCHAR( 50 )          ,
    state       VARCHAR( 50 )          ,
    country_id  CHAR( 2 )               , -- fk
    CONSTRAINT fk_locations_countries 
      FOREIGN KEY( country_id )
      REFERENCES countries( country_id ) 
      ON DELETE CASCADE
  );
-- warehouses
CREATE TABLE warehouses
  (
    warehouse_id decimal( 12, 0 ) PRIMARY KEY,
    warehouse_name VARCHAR( 255 ) ,
    location_id    decimal( 12, 0 ), -- fk
    CONSTRAINT fk_warehouses_locations 
      FOREIGN KEY( location_id )
      REFERENCES locations( location_id ) 
      ON DELETE CASCADE
  );
-- employees
CREATE TABLE employees
  (
    employee_id decimal( 12, 0 )  PRIMARY KEY,
    first_name VARCHAR( 255 ) NOT NULL,
    last_name  VARCHAR( 255 ) NOT NULL,
    email      VARCHAR( 255 ) NOT NULL,
    phone      VARCHAR( 50 ) NOT NULL ,
    hire_date  DATE NOT NULL          ,
    manager_id decimal( 12, 0 )        , -- fk
    job_title  VARCHAR( 255 ) NOT NULL,
    CONSTRAINT fk_employees_manager 
        FOREIGN KEY( manager_id )
        REFERENCES employees( employee_id )
        ON DELETE CASCADE
  );
-- product category
CREATE TABLE product_categories
  (
    category_id decimal PRIMARY KEY,
    category_name VARCHAR( 255 ) NOT NULL
  );

-- products table
CREATE TABLE products
  (
    product_id decimal( 12, 0 ) PRIMARY KEY,
    product_name  VARCHAR( 255 ) NOT NULL,
    description   VARCHAR( 2000 )        ,
    standard_cost decimal( 9, 2 )          ,
    list_price    decimal( 9, 2 )          ,
    category_id   decimal NOT NULL         ,
    CONSTRAINT fk_products_categories 
      FOREIGN KEY( category_id )
      REFERENCES product_categories( category_id ) 
      ON DELETE CASCADE
  );
-- customers
CREATE TABLE customers
  (
    customer_id decimal( 6, 0 ) PRIMARY KEY,
    name         VARCHAR( 255 ) NOT NULL,
    address      VARCHAR( 255 )         ,
    website      VARCHAR( 255 )         ,
    credit_limit decimal( 8, 2 )
  );
-- contacts
CREATE TABLE contacts
  (
    contact_id decimal PRIMARY KEY,
    first_name  VARCHAR( 255 ) NOT NULL,
    last_name   VARCHAR( 255 ) NOT NULL,
    email       VARCHAR( 255 ) NOT NULL,
    phone       VARCHAR( 20 )          ,
    customer_id decimal (6,0)                 ,
    CONSTRAINT fk_contacts_customers 
      FOREIGN KEY( customer_id )
      REFERENCES customers( customer_id ) 
      ON DELETE CASCADE
  );
-- orders table
CREATE TABLE orders
  (
    order_id decimal( 12, 0 )  PRIMARY KEY,
    customer_id decimal( 6, 0 ) NOT NULL, -- fk
    status      VARCHAR( 20 ) NOT NULL ,
    salesman_id decimal( 12, 0 )         , -- fk
    order_date  DATE NOT NULL          ,
    CONSTRAINT fk_orders_customers 
      FOREIGN KEY( customer_id )
      REFERENCES customers( customer_id )
      ON DELETE CASCADE,
    CONSTRAINT fk_orders_employees 
      FOREIGN KEY( salesman_id )
      REFERENCES employees( employee_id ) 
      ON DELETE SET NULL
  );
-- order items
CREATE TABLE order_items
  (
    order_id   decimal( 12, 0 )                                , -- fk
    item_id    decimal( 12, 0 )                                ,
    product_id decimal( 12, 0 ) NOT NULL                       , -- fk
    quantity   decimal( 8, 2 ) NOT NULL                        ,
    unit_price decimal( 8, 2 ) NOT NULL                        ,
    CONSTRAINT pk_order_items 
      PRIMARY KEY( order_id, item_id ),
    CONSTRAINT fk_order_items_products 
      FOREIGN KEY( product_id )
      REFERENCES products( product_id ) 
      ON DELETE CASCADE,
    CONSTRAINT fk_order_items_orders 
      FOREIGN KEY( order_id )
      REFERENCES orders( order_id ) 
      ON DELETE CASCADE
  );
-- inventories
CREATE TABLE inventories
  (
    product_id   decimal( 12, 0 )        , -- fk
    warehouse_id decimal( 12, 0 )        , -- fk
    quantity     decimal( 8, 0 ) NOT NULL,
    CONSTRAINT pk_inventories 
      PRIMARY KEY( product_id, warehouse_id ),
    CONSTRAINT fk_inventories_products 
      FOREIGN KEY( product_id )
      REFERENCES products( product_id ) 
      ON DELETE CASCADE,
    CONSTRAINT fk_inventories_warehouses 
      FOREIGN KEY( warehouse_id )
      REFERENCES warehouses( warehouse_id ) 
      ON DELETE CASCADE
  );


