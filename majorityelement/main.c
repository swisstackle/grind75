#include <stdio.h>
int majorityElement(int* nums, int numsSize){
	if(numsSize == 1) { // according to constraints, numsSize > 0
		return nums[0];
	}
	int count = 0;
	int candidate = nums[0];
	for(int i = 0; i < numsSize; i++){	
		if(nums[i] == candidate){
			count++;
		} else {
			count--;
		}
		if(count == 0){
			candidate = nums[i];
			count = 1;
		}
	}
	return candidate;
}
int main(){ 
	int test[13] = {1,3,1,1,4,1,1,5,1,1,6,2,2};
	printf("%d\n", majorityElement(test, 13));
}
