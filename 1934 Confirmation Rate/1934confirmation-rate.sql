# Write your MySQL query statement below
select s.user_id,round(
    IFNULL(sum(c.action='confirmed')/count(c.user_id),0),2) #IFNULL() return 0 if null;
    as confirmation_rate from signups s
    left join confirmations c on s.user_id=c.user_id
    group by s.user_id;
