-- Write an SQL query that will, for each user, return the number of followers.
SELECT
    user_id,
    COUNT(follower_id) AS followers_count
FROM
    followers
GROUP BY
    user_id
ORDER BY
    user_id;