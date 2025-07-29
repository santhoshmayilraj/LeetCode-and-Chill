-- Write your PostgreSQL query statement below
SELECT class 
FROM Courses 
GROUP BY class
HAVING count(student) > 4;