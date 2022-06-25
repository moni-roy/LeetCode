-- Write an SQL query to find the daily active user count for a period of 30 days ending 2019-07-27 inclusively. A user was active on someday if they made at least one activity on that day.
SELECT
    activity_date as day,
    COUNT(DISTINCT user_id) as active_users
FROM
    activity
WHERE
    DATEDIFF('2019-07-27', activity_date) < 30 AND DATEDIFF('2019-07-27', activity_date) >= 0
GROUP BY
    activity_date;