WITH loyal AS(
    SELECT customer_id,
           DATEDIFF(MAX(transaction_date),MIN(transaction_date)) AS trans_period,
           SUM(CASE WHEN transaction_type = 'purchase' THEN 1 ELSE 0 END) AS purchase_count,
           SUM(CASE WHEN transaction_type = 'refund' THEN 1 ELSE 0 END) AS refund_count,
           COUNT(*) AS total
        FROM customer_transactions
    GROUP BY customer_id  
)
SELECT customer_id 
FROM loyal
WHERE trans_period >= 30
      AND purchase_count >= 3
      AND refund_count*1.0/total < 0.2
    ORDER BY customer_id ASC;