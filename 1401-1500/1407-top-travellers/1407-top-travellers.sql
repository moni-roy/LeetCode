-- Write an SQL query to report the distance traveled by each user.Return the result table ordered by travelled_distance in descending order, if two or more users traveled the same distance, order them by their name in ascending order.
SELECT
    name,
    SUM(IFNULL(distance, 0)) AS travelled_distance
FROM
    users
    LEFT JOIN rides ON users.id = rides.user_id
GROUP BY
    users.id
ORDER BY
    travelled_distance DESC,
    name ASC;