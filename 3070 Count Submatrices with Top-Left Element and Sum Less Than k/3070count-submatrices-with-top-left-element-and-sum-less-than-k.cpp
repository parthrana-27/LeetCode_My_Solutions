class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        vector<vector<int>>pref(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pref[i+1][j+1]=grid[i][j]+pref[i+1][j]+pref[i][j+1]-pref[i][j];
                if(pref[i+1][j+1]<=k) c++;
            }
        }
        return c;
    }
};