#include <stdio.h>
 #include <stdbool.h>
 #include <stdlib.h>
 #include <math.h>
 #include<string.h>

char* merge(char* a,
char* b,
int aLength,
int bLength) {
    int totalLength = aLength + bLength;
    char* c = (char*)malloc(totalLength * sizeof(char));
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
char *mergeSort(char* nums, int numsSize) {
    if (numsSize == 1) {
        return nums;
    }
    char* firstHalf = nums;
    double thelength = numsSize / 2.0;
    int firstHalfLength = (int)ceil(thelength);
    char* secondHalf = nums + firstHalfLength;
    int secondHalfLength = (int)floor(thelength);
    char *l1 = mergeSort(firstHalf, firstHalfLength);
    char *l2 = mergeSort(secondHalf, secondHalfLength);
    char* returnArray = merge(l1, l2, firstHalfLength, secondHalfLength);
    return returnArray;
}

bool isAnagram(char * s, char * t){
    int length1 = strlen(s);
    int length2 = strlen(t);
    if (length1 != length2) {
        return false;
    }
    char *sorted1 = mergeSort(s, length1);
    char *sorted2 = mergeSort(t, length2);
    
    for(int i = 0; i < length1; i++) {
        if(sorted1[i] != sorted2[i]) {
            return false;
        }
    }
   return true;
}

int main(int argc, char *argv[]) {
    char *s = "anagrad";
    char *t = "nagaram";
    printf("%d", isAnagram(s,t));
}
