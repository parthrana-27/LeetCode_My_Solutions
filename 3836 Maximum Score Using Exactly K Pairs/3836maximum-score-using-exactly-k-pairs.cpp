class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(m+1,vector<long long>(k+1,-1e18)));
       for(int i=0;i<=n;i++){
           for(int j=0;j<=m;j++){
               dp[i][j][0]=0;
           }
       } 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int t=0;t<=k;t++){
                    dp[i][j][t]=max(dp[i][j][t],dp[i-1][j][t]);
                    dp[i][j][t]=max(dp[i][j][t],dp[i][j-1][t]);
                    if(t>0){
                        dp[i][j][t]=max(dp[i][j][t],dp[i-1][j-1][t-1]+1LL*nums1[i-1]*nums2[j-1]);
                    }
                }
            }
        }
        return dp[n][m][k];
    }
};