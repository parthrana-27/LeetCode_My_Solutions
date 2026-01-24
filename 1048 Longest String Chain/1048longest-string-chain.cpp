class Solution {
    private:
    bool check(string &a,string &b){
        if(a.size()!=b.size()+1) return 0;
        int i=0;
        int j=0;
        while(i<a.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==a.size() && j==b.size()) return true;
        return false;
    }
    static bool comp(string &a,string &b){
        return a.size()<b.size();
    }
public:
    int longestStrChain(vector<string>& arr) {
        int n=arr.size();
        vector<int>dp(n,1);
        sort(arr.begin(),arr.end(),comp);
        int ma=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++){
                if(check(arr[i],arr[j]) && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            if(dp[i]>ma){
                ma=dp[i];
            }
        }
        return ma;
    }
};