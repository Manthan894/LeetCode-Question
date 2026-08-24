# Write your MySQL query statement below
Select name As Customers from Customers 
Left Join Orders   ON   Orders.customerId = Customers.id 
where Orders.customerId IS NULL;