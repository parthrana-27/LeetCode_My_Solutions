class Solution {
    private:
    typedef long long ll;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mod=1e9+7;
        vector<vector<ll>>madp(n,vector<ll>(m));
        vector<vector<ll>>midp(n,vector<ll>(m));
        madp[0][0]=midp[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            madp[i][0]=midp[i][0]=madp[i-1][0]*grid[i][0];
        }
        for(int j=1;j<m;j++){
            madp[0][j]=midp[0][j]=madp[0][j-1]*grid[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                ll val=grid[i][j];
                vector<ll>c={madp[i-1][j]*val,midp[i-1][j]*val,madp[i][j-1]*val,midp[i][j-1]*val};
                madp[i][j]=*max_element(c.begin(),c.end());
                midp[i][j]=*min_element(c.begin(),c.end());
            }
        }
        ll ans=madp[n-1][m-1];
        if(ans<0) return -1;
        return int(ans%mod);
    }
};