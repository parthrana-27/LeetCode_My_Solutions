class Solution {
    private:
    bool f(string &s,int l,int r,vector<vector<bool>> &dp){
        if(r-l+1<2) return false;
        while(l<r && s[l]==s[r]){
            l++;
            r--;
        }
        if(l>=r) return true;
        if(l+1<=r && dp[l+1][r]) return true;
        if(l<=r-1 && dp[l][r-1]) return true;
        return false;
    }
public:
    int almostPalindromic(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int c=0;c<n;c++){
            int l=c,r=c;
            while(l>=0 && r<n && s[l]==s[r]){
                dp[l][r]=true;
                l--;
                r++;
            }
            l=c,r=c+1;
            while(l>=0 && r<n && s[l]==s[r]){
                dp[l][r]=true;
                l--;
                r++;
            }
        }
        for(int l=n;l>=2;l--){
            for(int i=0;i+l<=n;i++){
                if(f(s,i,i+l-1,dp)){
                    return l;
                }
            }
        }
        return 0;
    }
};