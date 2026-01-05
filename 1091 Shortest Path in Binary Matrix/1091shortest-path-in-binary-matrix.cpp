class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        queue<pair<int,int>>q;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        q.push({0,0});
        vector<int>dr={-1,-1,-1,0,0,1,1,1};
        vector<int>dc={-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                
                if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==0 && dist[r][c]+1 < dist[newr][newc]){
                    dist[newr][newc]=1+dist[r][c];
                    if(newr==n-1 && newc==n-1) return dist[newr][newc];
                    q.push({newr,newc});
                }
            }
        }
        return -1;
    }
};