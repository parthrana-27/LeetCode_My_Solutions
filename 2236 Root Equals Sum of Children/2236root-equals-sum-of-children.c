/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool checkTree(struct TreeNode* root) {
    int sum=root->left->val+root->right->val;
    if(root==NULL||root->left==NULL||root->right==NULL)
    {
        return false;
    }
    else{
        return root->val==root->left->val+root->right->val;
    }
}