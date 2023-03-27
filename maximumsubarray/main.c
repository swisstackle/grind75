#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// Returns the maximum of two integers
int max(int a, int b){
	if (a > b)
		return a;
	return b;
}
// Returns the maximum subarray sum of nums
int maxSubArray(int* nums, int numsSize){
	if (numsSize == 1){
		return nums[0];
	}

	// Create an array to store the maximum subarray sum ending at each index
	int *opt = (int*)calloc(sizeof(int), numsSize);
	opt[0] = nums[0];

	// Loop through the array and update opt with the maximum subarray sum ending at each index
	for (int i = 1; i < numsSize; i++) {
		opt[i] = max(nums[i], opt[i-1] + nums[i]);
	}

	// Find the maximum subarray sum by looping through opt
	int maxSum = opt[0];
	for (int i = 1; i < numsSize; i++) {
		if (opt[i] > maxSum) {
			maxSum = opt[i];
		}
	}
	return maxSum;
}

int main(){
	int nums[] =  {8,-19,5,-4,20};
	printf("%d\n", maxSubArray(nums, 5));
}

