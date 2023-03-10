#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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

int longestPalindrome(char * s){
	// Take the largest odd number occurance
	// Then modify the number of occurances of the rest of the letters to be even
	int length = strlen(s);
	if(length == 1) {
		return 1;	
	}
	char *sorted = mergeSort(s, length);
	print_char_array(sorted, length);
	int charCtr[length];
	for(int u = 0; u < length; u++) {
		charCtr[u]=0;
	}
	int next = 0;
	for(int i = 0; i < length; i++){
		if(i>0) {
			if(sorted[i] != sorted[i-1]){
				next++;
			}
		}
		charCtr[next]++;
	}

	int sum = 0;
	int hadOdd = 0;
	for(int j = 0; j < length; j++) {
		if(charCtr[j] % 2 != 0) {
			if(charCtr[j] % 2 != 0) {
				charCtr[j]--;
				hadOdd = 1;
			}
		}
		sum+=charCtr[j];
	}
	if(hadOdd) {
		return sum + 1;
	} else {
		return sum;
	}
}
int main() {
	char *test = "abcccdcd";
	printf("%d\n", longestPalindrome(test));
}
