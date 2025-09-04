CREATE OR REPLACE FUNCTION NthHighestSalary(N INT)
RETURNS TABLE (nth_salary INT) AS $$
BEGIN
    -- If N is less than 1, just return NULL
    IF N < 1 THEN
        RETURN QUERY SELECT NULL::INT;
        RETURN;
    END IF;

    RETURN QUERY
    SELECT salary
    FROM (
        SELECT DISTINCT salary
        FROM Employee
        ORDER BY salary DESC
        LIMIT 1 OFFSET N-1
    ) AS sub;
END;
$$ LANGUAGE plpgsql;
