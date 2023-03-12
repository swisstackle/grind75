# Exercise
https://leetcode.com/problems/majority-element
# Explanation
We have a count variable and a candidate variable.
We initlialize the candidate to be the first element.
Each time we encounter the current element to be equal to the candidate, we increment count.
Each time the current element is not equal to the candiadate, we decrement the count.
Once count hits 0, we set the candidate to the current element.
At the end, we return the candidate.

It works because if count hits 0, that means that there are atleast n / 2 other elements than the candidate, which means the candidate cant be the majority element. Thus, by process of elimination, at the end, the candidate will be the majority element.
