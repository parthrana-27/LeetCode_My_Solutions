/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    private:
    void preorder(TreeNode* node,string& res){
        if(!node) return;
        res+=to_string(node->val)+",";
        preorder(node->left,res);
        preorder(node->right,res);
    }
    TreeNode* build(vector<int>&arr,int& idx,int mi,int ma){
        if(idx>=arr.size()) return nullptr;
        int val=arr[idx];
        if(val<mi || val>ma) return nullptr;
        TreeNode* root=new TreeNode(val);
        idx++;
        root->left=build(arr,idx,mi,val);
        root->right=build(arr,idx,val,ma);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res;
        preorder(root,res);
        if(!res.empty()) res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        vector<int>val;
        stringstream ss(data);
        string seg;
        while(getline(ss,seg,',')){
            val.push_back(stoi(seg));
        }
        int idx=0;
        return build(val,idx,INT_MIN,INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;