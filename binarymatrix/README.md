# Exercise 
https://leetcode.com/problems/01-matrix
# Explanation
We use a `reverse` bfs to find the shortest path from each node to a 0.
First, we find all the 0's, mark them as visited and add them to the queue.
Then we start bfs and count  for each remaining node, how many steps you have to take to get to it.
So instead of finding the shortest path from each node to the 0, we start from the 0's on so that we 
don't have to run BFS for every single node.
Since we have to do only one BFS traversal, the runtime is `O(nm) whereas the slower solution by computing the BFS
for each cell individually would be O((nm)^2). First, i came up with the slower solution, but it ended up timing out on one of the
testcases.
