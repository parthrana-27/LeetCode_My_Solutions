class Solution {
    private:
    int f(int i,vector<int>& dp){
        if(i<=1) return 1;
        if(dp[i]!=-1) return dp[i];
        int c=0;
        for(int in=1;in<=i;in++){
            int left=f(in-1,dp);
            int right=f(i-in,dp);
            c+=left*right;
        }
        return dp[i]=c;
    }
public:
    int numTrees(int n){
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};