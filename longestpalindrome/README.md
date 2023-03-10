# Exercise
https://leetcode.com/problems/longest-palindrome

# Steps
1. Sort chars with merge sort
2. Count each chars and create charCtr array
3. Trim down each letter that occurs an odd number of times by 1
4. Add 1 to the result if there was an odd number of occurances since we can put 1 set of odd characters that occurs an odd number of times in the middle of the palindrome. For example: `dasssad` where s occurs odd number of times.
5. Return the sum
