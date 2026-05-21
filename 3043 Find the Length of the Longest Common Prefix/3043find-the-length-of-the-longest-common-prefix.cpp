class Solution {
    private:
    struct Node{
        Node* child[10];
        Node(){
            for(int i=0;i<10;i++){
                child[i]=nullptr;
            }
        }
    };
    void insert(Node* root,int num){
        string s=to_string(num);
        Node* cur=root;
        for(char c:s){
            int digit=c-'0';
            if(!cur->child[digit]){
                cur->child[digit]=new Node();
            }
            cur=cur->child[digit];
        }
    }
    int get(Node* root,int num){
        string s=to_string(num);
        Node* cur=root;
        int len=0;
        for(char c:s){
            int digit=c-'0';
            if(!cur->child[digit]){
                break;
            }
            len++;
            cur=cur->child[digit];
        }
        return len;
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.empty() || arr2.empty()) return 0;
        Node* root=new Node();
        for(int n:arr1) insert(root,n);
        int ma=0;
        for(int n:arr2){
            int cur=get(root,n);
            ma=max(ma,cur);
        }
        return ma;
    }
};