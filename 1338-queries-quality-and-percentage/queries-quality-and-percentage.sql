-- Write your PostgreSQL query statement below
SELECT query_name,ROUND(SUM(rating*1.0/position)/COUNT(*),2) AS quality,ROUND((SUM(Case WHEN rating < 3 THEN 1 ELSE 0 END)*1.0/COUNT(*))*100,2) AS poor_query_percentage
FROM Queries
GROUP BY query_name;