# Write your MySQL query statement below
select round(
    count(distinct case 
        when DATEDIFF(a.event_date,first_login.first_login_date)=1
            then a.player_id end)*1.0/count(distinct a.player_id),2)
            as fraction
    from activity a
    join (
        select player_id,min(event_date) as first_login_date
        from activity
        group by player_id
    ) first_login on a.player_id=first_login.player_id;