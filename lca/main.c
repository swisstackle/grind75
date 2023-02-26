#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<inttypes.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if((p->val < root->val && q->val > root->val) || (p->val > root->val && q->val < root->val )){
		return root;
	}

	if(p->val < root->val && q->val < root->val) {
		return lowestCommonAncestor(root->left, p, q);
	}

	if(p->val > root->val && q->val > root->val) {
		return lowestCommonAncestor(root->right, p, q);
	}
	return root;
}




int main() {
	struct TreeNode root;
	struct TreeNode left;
	struct TreeNode right;
	
	root.val = 5;
	root.left = &left;
	root.right = &right;
	left.val = 4;
	right.val = 3;

	left.left = NULL;
	left.right = NULL;
	right.left = NULL;
	right.right = NULL;

	lowestCommonAncestor(&root, &left, &right);
}
