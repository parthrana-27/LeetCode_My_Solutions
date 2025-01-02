/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int dfs(struct TreeNode* root,int cur)
 {
    if(!root) return 0;
    cur=cur*10+root->val;
    if(!root->left && !root->right)
    {
        return cur;
    }
    return dfs(root->left,cur)+dfs(root->right,cur);
 }
int sumNumbers(struct TreeNode* root) 
{
return dfs(root,0);
}