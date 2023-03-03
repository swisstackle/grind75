// Note: the function isBadVersion() is given as a black box on Leetcode. Therefore this exerc
// ise doesn't contain a Makefile or a main method.
int firstBadVersion(int n) {
	if(isBadVersion(1)) {
		return 1;
	}
   int start = 1, end = n;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(isBadVersion(mid) && !(isBadVersion(mid-1))){
            return mid;
        }
        else if(!(isBadVersion(mid))){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

