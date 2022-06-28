-- Write an SQL query to report the name and balance of users with a balance higher than 10000. The balance of an account is equal to the sum of the amounts of all transactions involving that account.
SELECT
    a.name,
    b.balance
FROM
    users AS a
    JOIN (
        SELECT
            account,
            SUM(amount) AS balance
        FROM
            transactions
        GROUP BY
            account
    ) AS b ON a.account = b.account
WHERE
    b.balance > 10000;