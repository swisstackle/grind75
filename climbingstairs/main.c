#include <stdio.h>



int climbStairs(int n) {
	if(n == 1) {
		return 1;
	}
	if(n == 2) {
		return 2;
	}
	if(n == 3) {
		return 3;
	}
	return climbStairs(n-2) + climbStairs(n-1);
}

int main(){
	printf("%d\n", climbStairs(45));
}
