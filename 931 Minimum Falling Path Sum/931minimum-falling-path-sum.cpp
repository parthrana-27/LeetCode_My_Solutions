class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++)
        {
            dp[0][j]=mat[0][j];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int u=mat[i][j]+dp[i-1][j];
                int ld=mat[i][j];
                if(j-1>=0) ld+=dp[i-1][j-1];
                else ld+=1e9;
                int rd=mat[i][j];
                if(j+1<n) rd+=dp[i-1][j+1];
                else rd+=1e9;
                dp[i][j]=min({u,ld,rd});
            }
        }
       int ans = 1e9;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[n - 1][j]);
        }
        return ans;
    }
};