/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    bool f(TreeNode* node,int cur,int t){
        if(!node) return false;
        cur+=node->val;
        if(!node->left && !node->right) return cur==t;
        return f(node->right,cur,t) || f(node->left,cur,t);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return f(root,0,targetSum);
    }
};