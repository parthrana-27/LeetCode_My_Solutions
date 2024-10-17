/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if(root==NULL)
    {
        return 0;
    }
    int l_level=1;
    struct TreeNode* temp_l=root->left;
    while(temp_l)
    {
        temp_l=temp_l->left;
        l_level++;
    }
    int r_level=1;
    struct TreeNode* temp_r=root->right;
    while(temp_r)
    {
        temp_r=temp_r->right;
        r_level++;
    }
    if(l_level==r_level)
    {
        return pow(2,l_level)-1;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}