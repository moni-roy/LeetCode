-- Write an SQL query that reports the products that were only sold in the first quarter of 2019. That is, between 2019-01-01 and 2019-03-31 inclusive.
SELECT
    p.product_id,
    p.product_name
FROM
    product p
    LEFT JOIN sales s ON p.product_id = s.product_id
GROUP BY
    p.product_id
HAVING
    MAX(s.sale_date) < '2019-04-01'
    AND MIN(s.sale_date) >= '2019-01-01';