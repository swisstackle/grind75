/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

int** dfs(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int oldColor){
    if(image[sr][sc] == oldColor) {
        image[sr][sc] = newColor;
        // processing north pixel
        if (sr >= 1) {  // check if not outta bounds
            dfs(image, imageSize, imageColSize, sr - 1, sc, newColor, oldColor);
        }
        // processing west pixel
        if(sc >= 1) {
            dfs(image, imageSize, imageColSize, sr, sc - 1, newColor, oldColor);
        }
        // processing east pixel

        if (sc < *imageColSize - 1) {
            dfs(image, imageSize, imageColSize, sr, sc + 1, newColor, oldColor);
        }
        // processing sout pixel
        if(sr < imageSize - 1) {
            dfs(image, imageSize, imageColSize, sr + 1, sc, newColor, oldColor);
        }
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize){
    int _color = image[sr][sc];
    *returnSize = imageSize;
    // Only necessary for Leetcode. Please see https://leetcode.com/submissions/detail/904316393/
    // *returnColumnSizes = (int*)malloc(sizeof(int) * *returnSize); 
    // for(int i = 0; i < *returnSize; i++){
    //     printf("%d\n", imageColSize[0]);
    //     (*returnColumnSizes)[i] = imageColSize[0];
    // }
    if(image[sr][sc] != color) {
            dfs(image, imageSize, imageColSize, sr, sc, color, image[sr][sc]);
    }
    return image;
}



int main() {
    int r = 3, c = 3, i, j, count;

    int** image = (int**)malloc(r * sizeof(int*));
    for (i = 0; i < r; i++)
        image[i] = (int*)malloc(c * sizeof(int));

    *(*(image + 0) + 0) = 1;
    *(*(image + 0) + 1) = 1;
    *(*(image + 0) + 2) = 1;
    *(*(image + 1) + 0) = 1;
    *(*(image + 1) + 1) = 1;
    *(*(image + 1) + 2) = 0;
    *(*(image + 2) + 0) = 1;
    *(*(image + 2) + 1) = 0;
    *(*(image + 2) + 2) = 1;
    int returnSize;
    int columnSize = 3;
    int **returnArray = floodFill(image, 3, &columnSize, 1, 1, 2, &returnSize);
    for(i=0; i<r; i++) {
      for(j=0;j<c;j++) {
         printf("%d ", returnArray[i][j]);
         if(j==c-1){
            printf("\n");
         }
      }
   }
}