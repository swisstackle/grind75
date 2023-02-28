# Problem
https://leetcode.com/problems/linked-list-cycle/

# Explanation

We use a special two pointer methods.
`slow` will take one step at a time in the linked list.
`fast` will take two step at a time in the linked list.

If there is a cycle, `fast` will catch `slow` from behind and therefore we can compare it with `slow == fast` to see if there is a cycle.
