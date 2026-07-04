WITH table_view AS (
    SELECT
        id,
        salary,
        DENSE_RANK() OVER(ORDER BY salary DESC) AS ranked_salary
    FROM Employee
)

-- Aggregate Function gives NULL if not present
SELECT MAX(salary) AS SecondHighestSalary 
FROM table_view
WHERE ranked_salary=2;