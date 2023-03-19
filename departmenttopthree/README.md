# Exercise
https://leetcode.com/problems/department-top-three-salaries
# Explanation
We use DENSE_RANK partitioned over department id to rank all employees by salary.
In the outter query, we only select the top 3 employees.
