-- Write your PostgreSQL query statement below
SELECT t1.name 
FROM Employee t1 INNER JOIN Employee t2
ON t1.id = t2.managerId
GROUP BY t2.managerId,t1.id,t1.name
HAVING count(t2.managerId) > 4;