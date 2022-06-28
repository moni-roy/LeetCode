-- Write an SQL query to report all the duplicate emails.
SELECT
    email as "Email"
FROM
    person
GROUP BY
    email
HAVING
    COUNT(*) > 1;