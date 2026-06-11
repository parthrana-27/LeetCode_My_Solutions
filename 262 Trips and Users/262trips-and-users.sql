# Write your MySQL query statement below
select request_at as Day,
round(
    sum(status != 'completed')/count(*), 2) as 'Cancellation Rate'
from trips
where client_id in (select users_id from users where banned='No')
and driver_id in(select users_id from users where banned='No')
and request_at between '2013-10-01' and '2013-10-03'
group by request_at;
