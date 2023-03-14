#include <stdio.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
int max(int a, int b){
	if(a > b)
		return a;
	return b;
}
int maxDepth(struct TreeNode *root){
	if(root == NULL){
		return 0;
	}
	int leftHeight = maxDepth(root->left);
	int rightHeight = maxDepth(root->right);
	return max(leftHeight, rightHeight) + 1;
}
int main(){
	struct TreeNode root, left, right;
	root.val = 0;
	root.right = &right;
	root.left = &left;

	left.val = 1;
	left.left = NULL;
	left.right = NULL;

	right.val = 1;
	right.left = NULL;
	right.right = NULL;

	printf("%d\n", maxDepth(&root));
}
