# Write your MySQL query statement below

SELECT DATE(sell_date) AS sell_date, COUNT(DISTINCT product) AS num_sold, GROUP_CONCAT(DISTINCT product) AS products FROM Activities GROUP BY DATE(sell_date) ORDER BY DATE(sell_date) ASC;