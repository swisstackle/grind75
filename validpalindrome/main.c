 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
bool isPalindrome(char * s){
    //remove all spaces
    //remove_spaces(s);
    int length = strlen(s);
    if (length < 2) {
        return true;
    } 
    // remove all non alphanumeric characters and convert upper to lower
    int alphanumericCount = 0;
    for (int i = 0; i < length; i++) {
        // Convert upper to lower
        if(s[i] > 64 && s[i] < 91) {
            s[i] = s[i] + 32;
        }
        // Remove non alphanumerig by backinserting
        if ((s[i] >= '0' && s[i] <= '9') ||
        (s[i] >= 'a' && s[i] <= 'z'))
        {  
            s[alphanumericCount] = s[i];
            alphanumericCount++;
        }
    }
    s[alphanumericCount] = '\0';

    // printf("%d %d %d %d", 'A', 'a', 'Z', 'z');
    printf("%s", s);
    length = strlen(s);
    // let's use the two pointer method to check if it is a palindrome
    int lastindex = length - 1;
    for (int i = 0; i < length; i++) {
        if (s[i] != s[lastindex]) {
            return false;
        }
        lastindex--;
     }
     return true;
}
int main() {
    char str[8] = "tacocat";
    isPalindrome(str);
}
