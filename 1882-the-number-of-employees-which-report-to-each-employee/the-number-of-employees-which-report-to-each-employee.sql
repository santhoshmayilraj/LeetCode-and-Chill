-- Write your PostgreSQL query statement below
SELECT t1.employee_id,t1.name,COUNT(t2.reports_to) AS reports_count,ROUND(AVG(t2.age)) AS average_age
FROM Employees t1 INNER JOIN Employees t2
ON t1.employee_id = t2.reports_to
GROUP BY t1.employee_id,t1.name
HAVING COUNT(t1.reports_to) IS NOT NULL
ORDER BY t1.employee_id;