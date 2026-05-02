class Solution {
public:
    int rotatedDigits(int n) {
        vector<int>dp(n+1,0);
        int c=0;
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int p=dp[i/10];
            int l=i%10;

            if(p==0){
                dp[i]=0;
                continue;
            }
            if(l==3 || l==4 || l==7){
                dp[i]=0;
            }else if(l==0 || l==1 || l==8){
                dp[i]=p;
            }else{
                dp[i]=2;
            }
            if(dp[i]==2){
                c++;
            }
        }
        return c;
    }
};