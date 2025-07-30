-- Write your PostgreSQL query statement below
SELECT DISTINCT(t1.num) AS ConsecutiveNums
FROM Logs t1
WHERE t1.id-1 IN (SELECT t2.id FROM Logs t2 WHERE t1.num = t2.num )
AND t1.id+1 IN (SELECT t2.id FROM Logs t2 WHERE t1.num = t2.num );
