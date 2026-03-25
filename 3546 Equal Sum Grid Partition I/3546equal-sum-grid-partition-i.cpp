class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        long long t=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                t+=grid[i][j];
            }
        }
        if(t%2!=0) return false;
        long long tar=t/2;
        long long s=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                s+=grid[i][j];
            }
            if(s==tar) return true;
        }
        s=0;
        for(int j=0;j<m-1;j++){
            for(int i=0;i<n;i++){
                s+=grid[i][j];
            }
            if(s==tar) return true;
        }
        return false;
    }
};