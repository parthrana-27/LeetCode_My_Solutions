class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxc=-1,maxr=-1,minr=m,minc=n;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    maxc=max(maxc,j);
                    maxr=max(maxr,i);
                    minr=min(minr,i);
                    minc=min(minc,j);

                }
            }
        }
        return (maxc-minc+1)*(maxr-minr+1);
    }
};