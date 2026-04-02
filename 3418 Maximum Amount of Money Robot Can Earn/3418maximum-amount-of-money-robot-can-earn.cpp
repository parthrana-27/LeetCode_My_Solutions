class Solution {
    private:
    int f(int i,int j,int k,vector<vector<int>>& coins,vector<vector<vector<int>>>& dp){
        if(i<0||j<0) return INT_MIN/2;
        if(i==0 && j==0){
            if(k>=(coins[0][0]<0?1:0)){
                return max(0,coins[0][0]);
            } return coins[0][0];
            }
            if(dp[i][j][k] != INT_MIN) return dp[i][j][k];
            int val=coins[i][j];
            int up=f(i-1,j,k,coins,dp);
            int left=f(i,j-1,k,coins,dp);
            int res=max(up,left);
            if(res != INT_MIN/2) res+=val;
            if(val<0 && k>0){
                int up=f(i-1,j,k-1,coins,dp);
                int left=f(i,j-1,k-1,coins,dp);
                int res2=max(up,left);
                if(res2 != INT_MIN/2){ 
                    res2+=0;
                    res=max(res,res2);
                }
            }
            return dp[i][j][k]=res;
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return f(n-1,m-1,2,coins,dp);
    }
};