class Solution {
private:
 int MOD=1e9+7;
 int n;
 int dp[201][201][201];
 int gcd(int a,int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
 }
 int f(int idx,int g1,int g2,vector<int>& arr){
    if(idx==n) return (g1>0 && g1==g2) ? 1:0;
    if(dp[idx][g1][g2] != -1) return dp[idx][g1][g2];
    long long c=0;
    int val=arr[idx];
    c=(c+f(idx+1,g1,g2,arr))%MOD;
    int ng1=(g1==0)?val:gcd(g1,val);
    c=(c+f(idx+1,ng1,g2,arr))%MOD;
    int ng2=(g2==0)?val:gcd(g2,val);
    c=(c+f(idx+1,g1,ng2,arr))%MOD;
    return dp[idx][g1][g2]=(int)c;
 }
public:
    int subsequencePairCount(vector<int>& arr) {
        n=arr.size();
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,arr);
    }
};