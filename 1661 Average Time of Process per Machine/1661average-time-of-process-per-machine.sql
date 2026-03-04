# Write your MySQL query statement below
select a.machine_id,
    round(
        (select avg(b.timestamp) from activity b where b.activity_type='end' and a.machine_id=b.machine_id)-
        (select avg(b.timestamp) from activity b where b.activity_type='start' and a.machine_id=b.machine_id)
        ,3) as processing_time
        from activity a
        group by a.machine_id;
