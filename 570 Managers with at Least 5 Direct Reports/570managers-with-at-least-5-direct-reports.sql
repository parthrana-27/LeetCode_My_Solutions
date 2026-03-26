# Write your MySQL query statement below
select e.name from employee e
join employee e1 on e.id=e1.managerId
group by e.name,e.id having count(e1.managerId)>=5;