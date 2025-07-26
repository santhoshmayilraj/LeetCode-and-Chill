-- Write your PostgreSQL query statement below
SELECT w2.id FROM Weather w1,Weather w2 Where w1.recordDate = w2.recordDate-1 AND w1.temperature < w2.temperature; 