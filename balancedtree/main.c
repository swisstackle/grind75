#include <stdio.h>
#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isBalanced(struct TreeNode* root){
	if(root->left != NULL) {
		isBalanced(root->left);
	}


	if(root->right != NULL) {
		isBalanced(root->right);
	}
	
	// we found a leaf
	printf("%d\n", root->val);
	return root;
}
int main() {
	struct TreeNode n1;
	struct TreeNode n2;
	struct TreeNode n3;
	struct TreeNode n4;
	struct TreeNode n5;

	n1.val = 3;
	n1.left = &n2;
	n1.right = &n3;

	n2.val = 9;
	n2.left = NULL;
	n2.right = NULL;

	n3.val = 20;
	n3.left = &n4;
	n3.right = &n5;

	n4.val = 15;
	n4.left = NULL;
	n4.right = NULL;

	n5.val = 7;
	n5.right = NULL;
	n5.left = NULL;

	isBalanced(&n1);

}
