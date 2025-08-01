-- Write your PostgreSQL query statement below
SELECT product_id,year AS first_year,quantity,price 
FROM Sales 
WHERE (product_id,year) IN 
(SELECT product_id,min(year) FROM
Sales GROUP BY product_id);