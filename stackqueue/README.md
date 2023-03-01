# Exercise

https://leetcode.com/problems/implement-queue-using-stacks

# Solution

We have two stacks. For pushing, we push onto the 'first' stack.
For popping, we take every element off the 'first' stack and push it onto the 'buffer' stack (except the very last element). Then we store the very last element in a temp variable and push all the elements from the buffer stack back onto the 'first' stack. Then we return that very last element because the very last element in the stack represents the first element in the queue.

For peeking, we do the same thing except that we push every element into the buffer stack, and then push every element back onto the 'first' stack, so that we don't delete any of the elements. Then we return the very last element that we pushed onto the buffer stack.

# Alternative Solution

We can also just use one stack as the back of the queue  and one stack as the front of the queue.
When an element is pushed onto the queue, it is pushed onto the back stack. When an element is popped from the queue or its value is read, the front stack is used to maintain the FIFO order of the elements.
