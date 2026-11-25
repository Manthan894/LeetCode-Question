# Write your MySQL query statement below
Select sub.product_name , s.year , s.price 
From Sales s , (
    Select p.product_id , product_name 
    From Product p
) sub 
Where s.product_id = sub.product_id;