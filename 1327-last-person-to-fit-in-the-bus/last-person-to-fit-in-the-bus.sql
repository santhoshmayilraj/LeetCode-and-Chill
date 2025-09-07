-- Write your PostgreSQL query statement below
WITH temp AS (
    SELECT person_id,person_name,sum(weight) OVER(ORDER BY turn) as total_weight
    FROM Queue 
)

SELECT person_name 
FROM temp 
WHERE total_weight <= 1000
ORDER BY total_weight DESC
LIMIT 1;


