WITH Ranks AS(
    SELECT student_id,
           subject,
           score,
           exam_date,
           FIRST_VALUE(score) OVER(
                PARTITION BY student_id,subject
                ORDER BY exam_date ASC
           ) AS first_score,
           FIRST_VALUE(score) OVER(
                PARTITION BY student_id,subject
                ORDER BY exam_date DESC
           ) AS latest_score
        FROM Scores
)
SELECT student_id,
       subject,
       first_score,
       latest_score
FROM Ranks
WHERE latest_score > first_score
GROUP BY student_id,subject
ORDER BY student_id,subject;