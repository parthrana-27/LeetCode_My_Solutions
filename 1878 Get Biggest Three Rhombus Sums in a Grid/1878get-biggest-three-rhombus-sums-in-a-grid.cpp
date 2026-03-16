class Solution {
    private:
    int getsum(vector<vector<int>>&grid,int i,int j,int sz){
        int x=i;
        int y=j;
        int sum=0;
        for(int k=0;k<sz;k++){
            x--;
            y++;
            sum+=grid[x][y];
        }
        for(int k=0;k<sz;k++){
            x++;
            y++;
            sum+=grid[x][y];
        }
        for(int k=0;k<sz;k++){
            x++;
            y--;
            sum+=grid[x][y];
        }
        for(int k=0;k<sz;k++){
            x--;
            y--;
            sum+=grid[x][y];
        }
        return sum;
    }
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<int>sums;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int sz=0; i-sz>=0 && i+sz<n && j+2*sz<m;sz++){
                    int sum=sz==0 ? grid[i][j]:getsum(grid,i,j,sz);
                    sums.insert(sum);
                    if(sums.size()>3) sums.erase(sums.begin());
                }
            }
        }
        return vector<int>(sums.rbegin(),sums.rend());
    }
};