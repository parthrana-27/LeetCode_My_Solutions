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
    typedef long long ll;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        ll ans=0;
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        while(!q.empty()){
            ll s=q.size();
            ll mi=q.front().second;
            ll f,l;
            for(int i=0;i<s;i++){
                ll cur=q.front().second-mi;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) f=cur;
                if(i==s-1) l=cur;
                if(node->left) q.push({node->left,cur*2+1});
                if(node->right) q.push({node->right,cur*2+2});
            }
            ans=max(ans,l-f+1);
        }
        return (int)ans;
    }
};