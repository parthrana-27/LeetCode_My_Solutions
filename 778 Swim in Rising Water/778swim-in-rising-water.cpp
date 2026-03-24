class Solution {
    private:
     int find(vector<int>& parent,int x) {
        if (parent[x]!=x) {
            parent[x]=find(parent,parent[x]);
        }
        return parent[x];
    }
    void unionSet(vector<int>& parent,vector<int>& rank,int x,int y){
        int px=find(parent,x);
        int py=find(parent,y);
        if(px==py) return;
        if(rank[px]<rank[py]){
            parent[px]=py;
        }else if(rank[px]>rank[py]){
            parent[py]=px;
        }else{
            parent[py]=px;
            rank[px]++;
        }
    }
    bool isvalid(int nrow,int ncol,int n){
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n ) return true;
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<tuple<int,int,int>>c;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                c.push_back({grid[i][j],i,j});
            }
        }
        sort(c.begin(),c.end());
        vector<int>parent(n*n);
        vector<int>rank(n*n,0);
        for(int i=0;i<n*n;i++){
            parent[i]=i;
        }
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,-1,0,1};
        for(auto& [e,i,j]:c){
            int idx=i*n+j;
            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(isvalid(nr,nc,n)){
                    int nidx=nr*n+nc;
                    if(grid[nr][nc]<=e){
                        unionSet(parent,rank,idx,nidx);
                    }
                }
            }
            if(find(parent,0) == find(parent,n*n-1)){
                return e;
            }
        }
        return -1;
    }
};