-- Write an SQL query to find all dates ' Id with higher temperatures compared to its previous dates (yesterday).
SELECT
    weather.id as ID
FROM
    Weather
    JOIN Weather as w ON DATEDIFF(weather.recordDate, w.recordDate) = 1
    AND weather.temperature > w.temperature