class Solution {
public:
    struct TrieNode{
    TrieNode* child[2];
    int cnt;
    TrieNode(){
        child[0]=child[1]=NULL;
        cnt=0;
        }
    };
    void insert(TrieNode* root,int num){
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!root->child[bit]) root->child[bit]=new TrieNode();
            root=root->child[bit];
            root->cnt++;
        }
    }
    int c(TrieNode* root,int num,int limit){
        int res=0;
        for(int i=31;i>=0;i--){
            if(!root) break;
            int nbit=(num>>i) & 1;
            int lbit=(limit>>i) & 1;
            if(lbit==1){
                if(root->child[nbit]) res+=root->child[nbit]->cnt;
                root=root->child[1-nbit];
            }
            else{
                root=root->child[nbit];
            }
        }
        return res;
    }
    int f(vector<int>& nums,int limit){
        if(limit<0) return 0;
        TrieNode* root=new TrieNode();
        int res=0;
        for(int num:nums){
            res+=c(root,num,limit);
            insert(root,num);
        }
        return res;
    }

    int countPairs(vector<int>& nums, int low, int high) {
        return f(nums,high+1)-f(nums,low);
    }
};