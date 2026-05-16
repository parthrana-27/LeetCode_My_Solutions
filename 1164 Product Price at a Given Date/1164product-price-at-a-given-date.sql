# Write your MySQL query statement below
with latest_price as (
    select product_id,new_price as price,
    row_number() over (partition by product_id order by change_date desc) as rn
    from products
    where change_date <= '2019-08-16' 
)
select product_id,price from latest_price
where rn=1
union 
select product_id,10 as price
from products where product_id not in (
    select product_id from products where change_date <= '2019-08-16'
);