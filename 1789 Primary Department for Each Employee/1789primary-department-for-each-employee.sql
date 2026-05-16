select employee_id,department_id
from (
    select employee_id,department_id,
    primary_flag,count(*) over (partition by employee_id) as dept_count
    from employee
) as subquery
where dept_count = 1 or primary_flag='Y'; 