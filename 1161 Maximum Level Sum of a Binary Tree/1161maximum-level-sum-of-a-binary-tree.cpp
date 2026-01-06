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
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*>q;
        unordered_map<int,int>mp;
        q.push(root);
        int l=1,m=1;
        int ma=root->val;
        while(!q.empty()){
            int s=q.size();
            int cur=0;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                cur+=node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            }
            if(cur > ma){
                ma=cur;
                m=l;
            }
            l++;
        }
        return m;
    }
};