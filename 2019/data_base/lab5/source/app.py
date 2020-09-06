import fire
import psycopg2
import locale 
from datetime import datetime

class Commands:
    def query1(self,date_str):
        con = psycopg2.connect("host = localhost dbname = 123 user = postgres password = 0")
        cur = con.cursor()
        time = datetime.strptime(date_str,'%B %Y')
        cur.execute("""
            SELECT products.product_name AS product_name, SUM(product_count) AS popularity
                FROM product_order
                    JOIN products ON products.product_id = product_order.product_id
                    JOIN orders ON orders.order_id = product_order.order_id
                        WHERE
                            EXTRACT(MONTH FROM orders.order_date) = EXTRACT(MONTH FROM date(%s)) AND
                            EXTRACT(YEAR FROM orders.order_date) = EXTRACT(YEAR FROM date(%s))
                    GROUP BY products.product_name
                    ORDER BY -SUM(product_count)
        """,( time.isoformat(), time.isoformat() )
        )
        result = cur.fetchall()
        print(result)
        cur.close()
        con.close()

    def query2(self,date_str):
        con = psycopg2.connect("host = localhost dbname = 123 user = postgres password = 0")
        cur = con.cursor()
        time = datetime.strptime(date_str,'%B %Y')
        cur.execute("""
            SELECT AVG(invoice_value) as avg_value
                FROM
                    (SELECT product_order.order_id as order_number, sum(product_order.product_count * products.product_cost_per_unit) AS invoice_value
                        FROM product_order
                            JOIN products ON products.product_id = product_order.product_id
                            JOIN orders ON orders.order_id = product_order.order_id
                                WHERE
                                    EXTRACT(MONTH FROM orders.order_date) = EXTRACT(MONTH FROM date(%s)) AND
                                    EXTRACT(YEAR FROM orders.order_date) = EXTRACT(YEAR FROM date(%s))
                            GROUP BY product_order.order_id
                            ORDER BY product_order.order_id) as sum_order
        """,( time.isoformat(), time.isoformat() )
        )
        result = cur.fetchall()
        print(result)
        cur.close()
        con.close()


if __name__ == '__main__':
    locale.setlocale(locale.LC_ALL,'ru_RU.utf8')        
    fire.Fire(Commands)
