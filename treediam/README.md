# Exercise
https://leetcode.com/problems/diameter-of-binary-tree/
# Explanation
We have a function to calcualte the height of the tree and use this function recursively in the `diameterOfTree` function.
In the `diameterOfTree` function, we calculate the height of both subtrees (`leftheight` and `rightHeight`) and add them. We also calculate the diameter of both subtrees with a recursive call to `diameterOfTree`. Of all the 4 values, we select the largest one as our final diameter.
