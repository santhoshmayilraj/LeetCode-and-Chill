-- Write your PostgreSQL query statement below
SELECT t1.product_id,ROUND(COALESCE(SUM(t1.price*t2.units)*1.0/SUM(t2.units),0),2) AS average_price
FROM Prices t1 LEFT JOIN UnitsSold t2
ON t1.product_id = t2.product_id 
AND t1.start_date <= t2.purchase_date 
AND t1.end_date >= t2.purchase_date
GROUP BY t1.product_id;