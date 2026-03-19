class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>pre_x(n+1,vector<int>(m+1,0));
        vector<vector<int>>pre_y(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cur_x=(grid[i][j]=='X'?1:0);
                int cur_y=(grid[i][j]=='Y'?1:0);
                pre_x[i+1][j+1]=cur_x+pre_x[i+1][j]+pre_x[i][j+1]-pre_x[i][j];
                pre_y[i+1][j+1]=cur_y+pre_y[i][j+1]+pre_y[i+1][j]-pre_y[i][j];
                if(pre_x[i+1][j+1]==pre_y[i+1][j+1] && pre_x[i+1][j+1]>0) ans++;
            }
        }
        return ans;
    }
};