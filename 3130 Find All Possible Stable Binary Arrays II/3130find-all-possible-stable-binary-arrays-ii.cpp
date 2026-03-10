class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>>dp(zero+1,vector<vector<long long>>(one+1,vector<long long>(2,0)));
        int mod=1e9+7;
        for(int i=1;i<=min(zero,limit);i++){
            dp[i][0][0]=1;
        }
        for(int j=1;j<=min(one,limit);j++){
            dp[0][j][1]=1;
        }
        for(int i=1;i<=zero;i++){
            for(int j=1;j<=one;j++){
                long long ways_zero=(dp[i-1][j][0]+dp[i-1][j][1])%mod;
                if(i-limit-1>=0){
                    ways_zero=(ways_zero-dp[i-limit-1][j][1]+mod)%mod;
                }
                dp[i][j][0]=ways_zero;
                long long ways_one=(dp[i][j-1][0]+dp[i][j-1][1])%mod;
                if(j-limit-1>=0){
                    ways_one=(ways_one-dp[i][j-limit-1][0]+mod)%mod;
                }
                dp[i][j][1]=ways_one;
            }
        }
        return (int)(dp[zero][one][0]+dp[zero][one][1])%mod;
    }
};