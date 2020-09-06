1. Рейтинг популярности товаров.
>рейтинг = кол-во проданных товаров за текущий месяц.
```sql
    SELECT products.product_name AS "Наименование продукта", SUM(product_count) AS "Рейтинг популярности"
	FROM product_order 
	JOIN products ON products.product_id = product_order.product_id
	JOIN orders ON orders.order_id = product_order.order_id 
		WHERE 
			EXTRACT(MONTH FROM orders.order_date) = EXTRACT(MONTH FROM NOW()) AND
			EXTRACT(YEAR FROM orders.order_date) = EXTRACT(YEAR FROM NOW())
	GROUP BY products.product_name
    ORDER BY -SUM(product_count)
```
2. Сумма среднего чека по магазину в разное время суток.
```sql
SELECT AVG("Стоимость чека") as "Средний чек"
FROM 
	(SELECT product_order.order_id as "Номер заказа", sum(product_order.product_count * products.product_cost_per_unit) AS "Стоимость чека"
		FROM product_order
		JOIN products ON products.product_id = product_order.product_id
		JOIN orders ON orders.order_id = product_order.order_id 
	 		WHERE
				EXTRACT(MONTH FROM orders.order_date) = EXTRACT(MONTH FROM NOW()) AND
				EXTRACT(YEAR FROM orders.order_date) = EXTRACT(YEAR FROM NOW())
		GROUP BY product_order.order_id
		ORDER BY product_order.order_id) as sum_order
```