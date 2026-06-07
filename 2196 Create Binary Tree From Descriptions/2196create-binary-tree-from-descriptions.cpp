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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>nodes;
        unordered_set<int>st;
        for(auto& d:descriptions){
            int parent=d[0];
            int child=d[1];
            int isleft=d[2];
            if(nodes.find(parent)==nodes.end()){
                nodes[parent]=new TreeNode(parent);
            }
            if(nodes.find(child)==nodes.end()){
                nodes[child]=new TreeNode(child);
            }
            if(isleft) nodes[parent]->left=nodes[child];
            else nodes[parent]->right=nodes[child];
            st.insert(child);
        }
        TreeNode* root=nullptr;
        for(auto it:nodes){
            if(st.find(it.first)==st.end()){
                root=it.second;
                break;
            }
        }
        return root;
    }
};