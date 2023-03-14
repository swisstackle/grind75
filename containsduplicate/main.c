#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int* merge(int* a,
int* b,
int aLength,
int bLength) {
    int totalLength = aLength + bLength;
    int* c = (int*)malloc(totalLength * sizeof(int));
    int cCounter = 0;
    while (aLength > 0 && bLength > 0) {
        if(a[0] > b[0]) {
            c[cCounter] = b[0];
            b = b + 1;
            bLength--;
            cCounter++;
        } else {
            c[cCounter] = a[0];
            a = a + 1;
            cCounter++;
            aLength--;
        }
    }
    while (aLength > 0) {
        c[cCounter] = a[0];
        a = a + 1;
        aLength--;
        cCounter++;
    }
    while(bLength > 0) {
        c[cCounter] = b[0];
        b = b + 1;
        bLength--;
        cCounter++;
    }

    return c;
}
void print_int_array(int *arr, size_t size) {
    if (size == 0) {
        printf("[]");
    } else {
        putchar('[');
        for (int i = 0; i < size - 1; i++)
            printf("%d, ", arr[i]);
        printf("%d]", arr[size - 1]);
    }

}
int *mergeSort(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums;
    }
    int* firstHalf = nums;
    double thelength = numsSize / 2.0;
    int firstHalfLength = (int)ceil(thelength);
    int* secondHalf = nums + firstHalfLength;
    int secondHalfLength = (int)floor(thelength);
    int *l1 = mergeSort(firstHalf, firstHalfLength);
    int *l2 = mergeSort(secondHalf, secondHalfLength);
    int* returnArray = merge(l1, l2, firstHalfLength, secondHalfLength);
    return returnArray;
}
bool containsDuplicate(int* nums, int numsSize){
	if(numsSize == 1){
		return false;
	}
	int* sorted = mergeSort(nums, numsSize);
	for(int i = 0; i < numsSize; i++){
		if(i != numsSize-1){
			if(sorted[i] == sorted[i+1]){
				return true;
			}
		} else {
			if(sorted[i] == sorted[i-1]){
				return true;
			}		
		}
	}
	return false;	
}
int main(){
	int test[4] = {1, 2, 3, 1};

	printf("%d\n", containsDuplicate(test, 4));
}
