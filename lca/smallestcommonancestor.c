struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* smallestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
     if(p->val >= root->val && q->val >= root->val) {
         return root;
     }
     if(p->val == root->val || q->val == root->val) {
         return root;
        }
     if((p->val < root->val && q->val > root->val) || (p->val > root->val && q->val < root->val )){
         return root;
     }
    return smallestCommonAncestor(root->left, p, q);
}
