# Write your MySQL query statement below
select Department,Employee,Salary
from (
    select d.name as Department,e.name as Employee,e.salary as Salary,
    DENSE_RANK() over (
        partition by e.departmentId
        order by e.salary desc
    ) as salary_rank
    from Employee e
    join department d on e.departmentId=d.id
)as rnk_emp
where salary_rank <= 3;