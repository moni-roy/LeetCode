-- Write an SQL query to find for each user, the join date and the number of orders they made as a buyer in 2019.
SELECT
    u.user_id as buyer_id,
    join_date, 
    IFNULL(COUNT(order_date), 0) as orders_in_2019
FROM
    users u
    LEFT JOIN orders o ON u.user_id = o.buyer_id
    AND YEAR(o.order_date) = '2019'
GROUP BY
    u.user_id;