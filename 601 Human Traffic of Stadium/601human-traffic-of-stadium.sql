WITH ConsecutiveGrp AS(
    SELECT id,
           visit_date,
           people,
           id-ROW_NUMBER() OVER(ORDER BY id) as grp
    FROM Stadium
    WHERE people >= 100
)
SELECT id,
       visit_date,
       people
    FROM ConsecutiveGrp
    WHERE grp IN(
    	SELECT grp
        FROM ConsecutiveGrp
        GROUP BY grp
        HAVING COUNT(*) >= 3
    ); 