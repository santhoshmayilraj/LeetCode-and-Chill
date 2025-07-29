-- Write your PostgreSQL query statement below
SELECT employee_id,department_id FROM
employee 
WHERE (employee_id,department_id) IN
(SELECT employee_id,MIN(department_id)
FROM employee 
GROUP BY employee_id 
HAVING COUNT(*) = 1
UNION 
SELECT employee_id,department_id 
FROM employee 
WHERE primary_flag = 'Y');
