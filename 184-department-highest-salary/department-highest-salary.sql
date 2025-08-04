-- Write your PostgreSQL query statement below
WITH temp AS (
    SELECT t2.id AS id,max(t1.salary) AS max_salary,t2.name AS dept_name
    FROM Employee t1 INNER JOIN Department t2
    ON t1.departmentId = t2.id
    GROUP BY t2.id,t2.name
)

SELECT t2.dept_name AS Department,t1.name AS Employee,t1.salary AS Salary
FROM Employee t1 INNER JOIN temp t2
ON t1.departmentId = t2.id AND t1.salary = t2.max_salary;