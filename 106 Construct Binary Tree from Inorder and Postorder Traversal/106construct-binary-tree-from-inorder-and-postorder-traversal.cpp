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
    int postidx;
    TreeNode* buildTreepost(vector<int>&inorder,int s,int e,vector<int>&postorder,map<int,int>& mp){
        if(s>e) return nullptr;
        int rootv=postorder[postidx--];
        TreeNode* root=new TreeNode(rootv);
        int inidx=mp[rootv];
        root->right=buildTreepost(inorder,inidx+1,e,postorder,mp);
        root->left=buildTreepost(inorder,s,inidx-1,postorder,mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!= postorder.size()) return NULL;
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        postidx=postorder.size()-1;
        return buildTreepost(inorder,0,inorder.size()-1,postorder,mp);
    }
};