-- Write your PostgreSQL query statement below
WITH temp AS(
    SELECT product_id,max(change_date) AS change_date
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
)

SELECT t1.product_id,t1.new_price AS price
FROM Products t1 INNER JOIN temp t2
ON t1.product_id = t2.product_id 
AND t1.change_date = t2.change_date
UNION ALL
SELECT t1.product_id,10 AS price 
From Products t1 
GROUP BY t1.product_id 
Having min(t1.change_date) >'2019-08-16';