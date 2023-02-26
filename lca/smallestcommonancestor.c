struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* smallestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
     // create dynamic parent array via dfs and then 
     // check parents and backtrack all ancestors and find the lowest one including themselves.
     //
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
