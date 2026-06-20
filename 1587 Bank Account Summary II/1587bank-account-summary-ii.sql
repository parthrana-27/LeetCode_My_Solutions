# Write your MySQL query statement below
SELECT u.name,
       SUM(t.amount) as balance
FROM transactions t
LEFT JOIN users u on t.account=u.account
GROUP BY u.account
HAVING balance > 10000;