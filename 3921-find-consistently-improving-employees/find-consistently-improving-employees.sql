WITH scores AS(
    SELECT employee_id,
           review_date,
           rating,
           ROW_NUMBER() OVER(
                PARTITION BY employee_id
                ORDER BY review_date DESC
           ) as rn
        FROM performance_reviews
),
LatestThree AS(
    SELECT employee_id,
           rating,
           rn
        FROM scores
    WHERE rn <= 3
),
pivot AS(
    SELECT employee_id,
           MAX(CASE WHEN rn = 1 THEN rating END) AS latest_rating,
           MAX(CASE WHEN rn = 2 THEN rating END) AS mid_rating,
           MAX(CASE WHEN rn = 3 THEN rating END) AS early_rating
        FROM LatestThree
        GROUP BY employee_id
        HAVING COUNT(*) = 3
)
SELECT p.employee_id,
       e.name,
       (p.latest_rating-p.early_rating) AS improvement_score
       FROM pivot p
    JOIN employees e ON p.employee_id=e.employee_id
    WHERE p.latest_rating > p.mid_rating
    AND   p.mid_rating > p.early_rating
    ORDER BY improvement_score DESC,
             e.name ASC;


