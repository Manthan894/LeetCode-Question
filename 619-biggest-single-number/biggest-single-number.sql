# Write your MySQL query statement below
Select IFNULL(
(Select num 
From MyNumbers
Group By num
Having Count(num) = 1
Order By num DESC
Limit 1),NULL) As num;