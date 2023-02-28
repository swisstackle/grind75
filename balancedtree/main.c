#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int l, int r) {
	if(l > r) {
		return l;
	}
	return r;
}

int help(struct TreeNode *root) {
	if(root==NULL){
		return 0;
	}
	int l=help(root->left);
    int r=help(root->right);
    if(l==-1 || r==-1){
		return -1;
	}
    if(abs(l-r)>1){
		return -1;
	}
    return 1+max(l, r);	
}

bool isBalanced(struct TreeNode* root){

	return help(root) != -1;
}


int main() {
	struct TreeNode n1;
	struct TreeNode n2;
	struct TreeNode n3;
	struct TreeNode n4;
	struct TreeNode n5;

	struct TreeNode n6;
	struct TreeNode n7;
	
	n1.val = 0;
	n1.left = NULL;
	n1.right = &n2;

	n2.val = 1;

	n2.left = NULL;
	n2.right = &n3;

	n3.val=2;
	n3.right=NULL;
	n3.left=NULL;

	bool is = isBalanced(&n1);
	printf("%d\n", is);

}
