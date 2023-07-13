# Write your MySQL query statement below

SELECT employee_id, salary * (CASE WHEN employee_id % 2 = 1 AND name NOT LIKE 'M%' THEN 1 ELSE 0 END) AS bonus FROM Employees order by employee_id;