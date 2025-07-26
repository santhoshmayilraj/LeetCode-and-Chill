-- Write your PostgreSQL query statement below
SELECT t1.name,t2.bonus 
FROM Employee t1 LEFT JOIN Bonus t2
ON t1.empId = t2.empId 
WHERE t2.bonus < 1000 
OR t2.bonus IS NULL; 