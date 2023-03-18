# Exercise
https://leetcode.com/problems/consecutive-numbers/
# Explanation
We use the	case function to filter out	`num's` that appear 3 times conseqetively. We use the `lag` function to check previous values within the `case` function.
Finally, we drop all values that are `null` with `WHERE ConsecutiveNums IS NOT NULL`
