class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int suff=1;
        vector<int>pref{1};
        vector<vector<int>>ans(n,vector<int>(m,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pref.push_back((1LL*pref.back()*grid[i][j])%12345);
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ans[i][j]=((pref[i*m+j]*suff)%12345);
                suff=(1LL*suff*grid[i][j])%12345;
            }
        }
        return ans;
    }
};