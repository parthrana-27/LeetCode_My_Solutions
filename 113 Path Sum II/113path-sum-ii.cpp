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
    void f(TreeNode* node,vector<int>& path,vector<vector<int>>& ans,int cur){
        if(!node) return;
        path.push_back(node->val);
        cur-=node->val;
        if(!node->left && !node->right && cur==0) ans.push_back(path);

        f(node->left,path,ans,cur);
        f(node->right,path,ans,cur);

        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;
        f(root,path,ans,targetSum);
        return ans;
    }
};