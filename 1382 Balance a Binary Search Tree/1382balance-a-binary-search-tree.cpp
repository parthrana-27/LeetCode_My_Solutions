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
    void inorder(TreeNode* root,vector<int>&vals){
        if(!root) return;
        inorder(root->left,vals);
        vals.push_back(root->val);
        inorder(root->right,vals);
    }
    TreeNode* f(vector<int> &vals,int l,int r){
        if(l>r) return nullptr;
        int mid=(l+r)>>1;
        TreeNode* node=new TreeNode(vals[mid]);
        node->left=f(vals,l,mid-1);
        node->right=f(vals,mid+1,r);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>vals;
        inorder(root,vals);
        return f(vals,0,vals.size()-1);
    }
};