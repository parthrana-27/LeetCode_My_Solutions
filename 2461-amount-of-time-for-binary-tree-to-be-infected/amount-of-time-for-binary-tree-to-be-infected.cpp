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
    int bfs(unordered_map<TreeNode*,TreeNode*>& mp,TreeNode* target){
        queue<TreeNode*>q;
        int ans=0;
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        q.push(target);
        while(!q.empty()){
             int s=q.size();
            bool fl=false;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left]=1;
                    q.push(node->left);
                    fl=true;
                }
                if(node->right && !vis[node->right]){
                    vis[node->right]=1;
                    q.push(node->right);
                    fl=true;
                }
                if(mp[node] && !vis[mp[node]]){
                    vis[mp[node]]=1;
                    q.push(mp[node]);
                    fl=true;
                }
            }
            if(fl) ans++;
        }
        return ans;
    }
    TreeNode* find(unordered_map<TreeNode*,TreeNode*>& mp,int target,TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==target) res=node;
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>mp;
        TreeNode* tar=find(mp,start,root);
        return bfs(mp,tar);
    }
};