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
    const int mod=1e9+7;
    long long ans=INT_MIN;
    long long total=0;
    private:
    int findsum(TreeNode* node,long long &ans){
        if(!node) return 0;
        int sum=node->val+findsum(node->left,ans)+findsum(node->right,ans);
        ans=max(ans,(total-sum)*sum);
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        total=findsum(root,ans);
        findsum(root,ans);
        return ans%mod;
    }
};