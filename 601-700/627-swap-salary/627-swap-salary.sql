# Write your MySQL query statement below
UPDATE
    Salary
SET
    sex = Case
        sex
        WHEN 'm' THEN 'f'
        ELSE 'm'
    END;