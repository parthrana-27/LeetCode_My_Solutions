class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(!k) return grid;
        int n=grid.size();
        int m=grid[0].size();
        int t=m*n;
        k=k%t;
        vector<vector<int>>res(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int old=i*m+j;
                int n_ind=(old+k)%t;
                int nr=n_ind/m;
                int nc=n_ind%m;
                res[nr][nc]=grid[i][j];
            }
        }
        return res;
    }
};