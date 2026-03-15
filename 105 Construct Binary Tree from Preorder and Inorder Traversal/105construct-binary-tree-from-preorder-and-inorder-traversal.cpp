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
    unordered_map<int,int>mp;
    int pre=0;
    TreeNode* build(vector<int>& preorder,int st,int end){
        if(st>end) return nullptr;
        int rootv=preorder[pre++];
        int ind=mp[rootv];
        TreeNode* root=new TreeNode(rootv);
        root->left=build(preorder,st,ind-1);
        root->right=build(preorder,ind+1,end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,0,inorder.size()-1);
    }
};