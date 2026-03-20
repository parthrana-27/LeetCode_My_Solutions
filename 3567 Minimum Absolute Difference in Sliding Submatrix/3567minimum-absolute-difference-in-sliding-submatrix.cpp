class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1,0));
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                vector<int>vals;
                for(int r=i;r<i+k;r++){
                    for(int c=j;c<j+k;c++){
                        vals.push_back(grid[r][c]);
                    }
                }
                sort(vals.begin(),vals.end());
                int mi=INT_MAX;
                for(int x=1;x<vals.size();x++){
                    if(vals[x]!=vals[x-1]) mi=min(mi,vals[x]-vals[x-1]);
                }
                ans[i][j]=(mi==INT_MAX)?0:mi;
            }
        }
        return ans;
    }
};