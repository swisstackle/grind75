# Exercise
https://leetcode.com/problems/climbing-stairs/
# Explanation
We use dynamic programming to solve the problem
## DP Formula
Basecase: `N = 1`
In this case, we have 1 possibility. So `OPT(N=1) = 1`
Basecase: `N = 2`
In this case, we have 2 possibilities. Either make 2 1steps or 1 2step. So OPT(N=2) = 2.

`OPT(3) = (OPT(1) + OPT(2))`  because we can either take 1 step and then 2 steps or take 2 steps and then 1 step. 

`OPT(4) = OPT(3) + OPT(2) = 5`

So the generic formula is:

`OPT(N=x) = OPT(N-2) + OPT(N-1)`



