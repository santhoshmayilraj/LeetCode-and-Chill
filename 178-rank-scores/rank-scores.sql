-- Write your PostgreSQL query statement below
SELECT
  s1.score,dense_rank() OVER(ORDER BY score DESC) AS rank

FROM
  Scores AS s1
ORDER BY
  s1.score DESC;