#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

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
void print_char_array(char *arr, size_t size) {
    if (size == 0) {
        printf("[]");
    } else {
        putchar('[');
        for (int i = 0; i < size - 1; i++)
            printf("%c, ", arr[i]);
        printf("%c]", arr[size - 1]);
    }

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

bool canConstruct(char *ransomNote, char *magazine) {
	int l1 = strlen(ransomNote);
	int l2 = strlen(magazine);
    if(l1 > l2) {
		return false;
	}
	char *sorted = mergeSort(ransomNote, l1);
	char *sorted2 = mergeSort(magazine, l2);
	int ptr = 0;
	for(int i = 0; i < l2; i++) {
		if(sorted2[i]==sorted[ptr]){
			ptr++;
			if(ptr==l1){
				return true;
			}
		}
	}
	return false;
}

int main() {

	char *mag = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj";
	char *ran = "bg";

	bool has = canConstruct(ran, mag);
	printf("%d\n", has);

	
}
