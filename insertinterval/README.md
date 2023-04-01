# Exercise 
https://leetcode.com/problems/insert-interval
# Explanation
This is an `O(n)` variant. There is an `O(log n)` variant that uses binary search to find the overlapping intervals (nothing crazy).

We have a while loop. If the new interval comes prior the start of the first interval in `intervals`, then we don't have to remove any intervals and we skip the process and insert it into the beginning,
If the interval is overlapping, we remove the interval.
If we don't remove an interval, we increase the index that we will insert the `new_interval` to by 1.

