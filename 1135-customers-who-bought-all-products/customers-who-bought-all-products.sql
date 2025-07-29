-- Write your PostgreSQL query statement below
SELECT customer_id 
FROM Customer 
GROUP BY customer_id
HAVING count(DISTINCT(product_key)) = (SELECT COUNT(*) FROM Product);