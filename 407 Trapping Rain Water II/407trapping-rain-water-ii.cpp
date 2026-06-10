class Solution {
public:
    int trapRainWater(vector<vector<int>>& mp){
        int m=mp.size();
        int n=mp[0].size();
        if(m<3||n<3) return 0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    pq.push({mp[i][j],i,j});
                    vis[i][j]=true;
                }
            }
        }
        int trap=0;
        vector<int>rows={-1,0,1,0};
        vector<int>cols={0,-1,0,1};
        while(!pq.empty()){
            auto [h,r,c]=pq.top();
            pq.pop();
            for(int i=0;i<4;i++){
                int nr=r+rows[i];
                int nc=c+cols[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc]){
                    vis[nr][nc]=true;
                    if(mp[nr][nc]<h){
                        trap+=(h-mp[nr][nc]);
                        pq.push({h,nr,nc});
                    }else{
                        pq.push({mp[nr][nc],nr,nc});
                    }
                } 
            }
        }
        return trap;
    }
};