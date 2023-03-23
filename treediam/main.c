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
int depth(struct TreeNode *root){
	if(root == NULL){
		return 0;
	}
	int leftHeight = depth(root->left);
	int rightHeight = depth(root->right);
	return max(leftHeight, rightHeight) + 1;
}
int diameterOfBinaryTree(struct TreeNode *of){
	int left_d = depth(of->left);
	int right_d = depth(of->right);
	int left_diam = 0;
	int right_diam = 0;
	if(of->left	!= NULL)
		 left_diam = diameterOfBinaryTree(of->left);
	if(of->right != NULL)
		 right_diam = diameterOfBinaryTree(of->right);
	return max(left_d + right_d, max(left_diam, right_diam));
}
int main(){
	struct TreeNode one;
	struct TreeNode two;
	struct TreeNode three;
	struct TreeNode four;
	struct TreeNode five;

	one.left = &two;
	one.right = &three;

	two.left = &four;
	two.right = &five;

	three.left = NULL;
	three.right = NULL;

	four.left = NULL;
	four.right = NULL;

	five.left = NULL;
	five.right = NULL;

	one.val = 1;
	two.val = 2;
	three.val = 3;
	four.val = 4;
	five.val = 5;
	
	printf("%d\n", diameterOfBinaryTree(&one));
}
