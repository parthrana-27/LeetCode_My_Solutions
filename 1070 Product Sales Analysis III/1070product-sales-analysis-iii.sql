# Write your MySQL query statement below
with first_year as(
    select product_id,min(year) as min_year from sales
    group by product_id
)
select s.product_id,f.min_year as first_year,s.quantity,s.price
from sales s
join first_year f on s.product_id = f.product_id and s.year=f.min_year;