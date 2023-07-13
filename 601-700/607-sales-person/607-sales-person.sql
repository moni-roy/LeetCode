-- Write an SQL query to report the names of all the salespersons who did not have any orders related to the company with the name "RED".
SELECT
    s.name
FROM
    Salesperson s
WHERE
    s.sales_id NOT IN (
        SELECT
            o.sales_id
        FROM
            orders o
        WHERE
            o.com_id IN (
                SELECT
                    c.com_id
                FROM
                    company c
                WHERE
                    c.name = 'RED'
            )
    )