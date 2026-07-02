class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        health-=grid[0][0];
        if(health<=0) return false;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        queue<tuple<int,int,int>>q;
        vector<int>dr={0,-1,0,1};
        vector<int>dc={-1,0,1,0};
        dp[0][0]=health;
        q.push({0,0,health});
        while(!q.empty()){
            auto [r,c,h]=q.front();
            q.pop();
            if(r==n-1 && c==m-1){
                return true;
            }
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 || nr>=n || nc<0 || nc>=m){
                    continue;
                }
                int nh=h-grid[nr][nc];
                if(nh<=0) continue;
                if(nh>dp[nr][nc]){
                    dp[nr][nc]=nh;
                    q.push({nr,nc,nh});
                }
            }
        }
        return false;
    }
};