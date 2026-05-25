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
    vector<TreeNode*> f(int s,int e){
        vector<TreeNode*>t;
        if(s>e){
            t.push_back(nullptr);
            return t;
        }
        for(int i=s;i<=e;i++){
            vector<TreeNode*> l=f(s,i-1);
            vector<TreeNode*> r=f(i+1,e);
            for(TreeNode* left:l){
                for(TreeNode* right:r){
                    TreeNode* root=new TreeNode(i);
                    root->right=right;
                    root->left=left;
                    t.push_back(root);
                }
            }
        }
        return t;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return f(1,n);
    }
};