class Solution {
public:
    double champagneTower(int poured, int q_row, int q_glass) {
        vector<vector<double>>dp(q_row+2,vector<double>(q_row+2,0.0));
        dp[0][0]=poured;

        for(int i=0;i<=q_row;i++){
            for(int j=0;j<=i;j++){
                if(dp[i][j]>1.0){
                    double ex=dp[i][j]-1.0;
                    dp[i][j]=1.0;
                    dp[i+1][j]+=ex/2.0;
                    dp[i+1][j+1]+=ex/2.0;
                }
            }
        }
        return min(1.0,dp[q_row][q_glass]);
    }
};