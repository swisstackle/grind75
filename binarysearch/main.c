#include <math.h>
#include <stdio.h>

int search(int* nums, int numsSize, int target) {
   int start = 0, end = numsSize - 1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int nums[6] = {-1,0,3,5,9,12};
    int index = search(&nums[0], 6, 13);
    printf("%d\n", index);
}
