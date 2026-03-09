class Solution {
private:

    void make_p(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            if(cur->left){
                parent[cur->left] = cur;
                q.push(cur->left);
            }

            if(cur->right){
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }

public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k){

        unordered_map<TreeNode*,TreeNode*> parent;
        make_p(root,parent);

        unordered_map<TreeNode*,bool> vis;

        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;

        int cur_lvl = 0;

        while(!q.empty()){

            int s = q.size();

            if(cur_lvl == k) break;
            cur_lvl++;

            for(int i=0;i<s;i++){

                TreeNode* cur = q.front();
                q.pop();

                if(cur->left && !vis[cur->left]){
                    q.push(cur->left);
                    vis[cur->left] = true;
                }

                if(cur->right && !vis[cur->right]){
                    q.push(cur->right);
                    vis[cur->right] = true;
                }

                if(parent.count(cur) && !vis[parent[cur]]){
                    q.push(parent[cur]);
                    vis[parent[cur]] = true;
                }
            }
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};