class Solution {
    private:
    void f(int val,int k,int n,vector<int>temp,vector<vector<int>>& ans){
        if(temp.size()==k && n==0){ans.push_back(temp);return;}
        if(temp.size()>k || n<0) return;
        for(int i=val;i<=9;i++){
            temp.push_back(i);
            f(i+1,k,n-i,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>ans;
        f(1,k,n,temp,ans);
        return ans;
    }
};