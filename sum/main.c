/**
 * We will use two pointer. First, we have to sort
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>

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

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* returnArray = (int*)malloc(2 * sizeof(int));
    int i = 0;
    int j = numsSize - 1;
    int* oldNums = nums;
    nums = mergeSort(nums, numsSize);

    while (i < j) {
        if ((nums[i] + nums[j]) == target) {
            // We have to find the indicies of the old array. This is still overall O(nlogn) because this happens only one time.
            int actualIndex1 = -1;
            int actualIndex2 = -1;
            int ontheline = 0;
            for(int k = 0; k < numsSize; k++) {
                if (nums[i] == oldNums[k] && ontheline == 0) {
                    actualIndex1 = k;
                    ontheline = 1;
                }
                if (nums[j] == oldNums[k] && ontheline == 1) {
                    actualIndex2 = k;
                }
            }
            returnArray[0] = actualIndex1;
            returnArray[1] = actualIndex2;
            *returnSize = 2;
            return returnArray;
        } else if (nums[i] + nums[j] < target) {
            i++;
        } else {
            j--;
        }
    }
    *returnSize = 0;
    return 0;
}

int main(int argc, char *argv[]) {
    int array1[3] = {1,2,8};
    int array2[4] = {-1,-2,-3,-4,-5};

    int toSort[5] = {-1,-2,-3,-4,-5};
    int returnSize = 2;
    int* two = twoSum(toSort, 5, -8, &returnSize);


    print_int_array(two, 2);
}

