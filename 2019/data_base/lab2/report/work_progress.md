**Содержимое запроса для создания таблиц**

```sql
CREATE TYPE enum_post AS ENUM ('intern','supervisor', 'cashier');
CREATE TYPE enum_discount_сat AS ENUM ('none','-50%', '-10%');

CREATE TABLE contact_datas(phone_number varchar(255) PRIMARY KEY,
                          first_name varchar(255) NOT NULL,
                          second_name varchar(255) NOT NULL,
                          email varchar(255)
                         );

CREATE TABLE suppliers(supplier_id SERIAL PRIMARY KEY,
                       adress varchar(255) NOT NULL
                     );

CREATE TABLE products(product_id SERIAL PRIMARY KEY,
                      supplier_id integer REFERENCES suppliers,
                      product_cost_per_unit real CONSTRAINT positive_price CHECK (product_cost_per_unit > 0),
                      product_name varchar(255) NOT NULL,
                      supply_date date not null default CURRENT_DATE,
                      amount integer not null default 0 CONSTRAINT positive_amount CHECK (amount > 0)
                     );

CREATE TABLE shops(shop_id SERIAL PRIMARY KEY,
                   adress varchar(255) NOT NULL
                  );

CREATE TABLE customers(customer_id SERIAL PRIMARY KEY,
                       contact_data varchar(255) REFERENCES contact_datas,
                       discount enum_discount_сat default 'none'
                      );
                      
CREATE TABLE employees(employee_id SERIAL PRIMARY KEY,
                       contact_data varchar(255) REFERENCES contact_datas,
                       post enum_post DEFAULT 'intern'
                      );

CREATE TABLE orders(order_id SERIAL PRIMARY KEY,
                    employee_id int REFERENCES employees,
                    customer_id int REFERENCES customers,
                    order_date DATE default CURRENT_DATE
                   );
                 
CREATE TABLE product_shop(shop_id integer REFERENCES shops,
                          product_id integer REFERENCES products,
                          CONSTRAINT product_shop_pkey PRIMARY KEY (shop_id, product_id) 
                         );

CREATE TABLE product_order(product_id integer REFERENCES products,
                          order_id integer REFERENCES orders,
                          product_count integer CONSTRAINT positive_count CHECK (product_count > 0),
                          CONSTRAINT product_order_pkey PRIMARY KEY (product_id, order_id) 
                         );
```
**Содержимое запросов для заполнения таблиц**

```sql
INSERT INTO "contact_datas" (phone_number,first_name,second_name,email)
	             VALUES ('+79205932034','Савельев','Семен',NULL),
	             		('+79104352124','Ушаков ','Филипп','pabidowod@net2mail.top'),
	             		('+79102361734','Филипов ','Иван','sdfwet@mail.org'),
	             		('+79205932063','Ерофеев','Виталий',NULL);
	             		
INSERT INTO "suppliers" (adress)
	             VALUES ('ул. Номер 1 д. 11'),
	             		('ул. Номер 1 д. 16');

INSERT INTO "products"(supplier_id,product_cost_per_unit,product_name,amount)
	             VALUES (1,100,'Яблоки зеленые',100),
                      (1,60,'Молоко',100),
                      (1,160,'Апельсины',100),
                      (1,600,'Сыр',100),
                      (1,100,'Крупа гречневая',100),
                      (1,100,'Крупа перловая',100),
                      (1,100,'Картофель',100),
                      (1,100,'Лук репчатый',100),
                      (1,100,'Сыр плавленый',100),
	             		    (1,120,'Яблоки красные',150);
	             		
INSERT INTO "shops"(adress)
	             VALUES ('ул. Номер 1 д. 10'),
	             		    ('ул. Номер 2 д. 13');
	             		
INSERT INTO "customers"(contact_data)
	             VALUES ('+79205932034'),
	             		    ('+79102361734');

INSERT INTO "employees"(contact_data)
	             VALUES ('+79104352124'),
	             		    ('+79205932063');

INSERT INTO "orders"(employee_id,customer_id,)
	             VALUES (1,2),
	             		    (1,2),
	             		    (1,2),
	             		    (1,2),
	             		    (1,2),
	             		    (1,2),
	             		    (1,2),
	             		    (1,2),
	             		    (1,2),
	             		    (1,2),
	             		    (1,2),
	             		    (1,2),
	             		    (1,2),
	             		    (1,2);

INSERT INTO "product_order"(order_id,product_id,product_count)
	             VALUES 	(1,7,3),
							(1,1,1),
							
							(2,7,3),							
							
							(3,4,1),
							(3,7,1),
							
							(4,4,1),
	             		    (4,7,1),
							
							(5,8,1),
	             		    (5,7,1),
							
							(6,1,1),	
	             		    (6,7,1),
							
	             		    (7,7,1),
							
							(8,8,1),
	             		    (8,2,1),
							
	             		    (9,8,1),
							(9,2,1),
							
							(10,1,1),							
	             		    (10,2,1);
```



