# Exercise
https://leetcode.com/problems/maximum-subarray
# Explanation
We use the dynamic programming method.
First, we find `max(nums[i], opt[i-1] + nums[i]` at each iteration and then we check which one is the largest to account for different combinations.
