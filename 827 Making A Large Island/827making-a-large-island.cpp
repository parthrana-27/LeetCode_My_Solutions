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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>parent(n*n);
        vector<int>rank(n*n,0);
        vector<int>s(n*n,0);
        for(int i=0;i<n*n;i++){
            parent[i]=i;
        }
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int in=0;in<4;in++){
                    int nr=dr[in]+i;
                    int nc=dc[in]+j;
                    if(isvalid(nr,nc,n) && grid[nr][nc]==1){
                        int nodeno=i*n+j;
                        int adjnode=nr*n+nc;
                        unionSet(parent,rank,nodeno,adjnode);
                    }
                }
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int p=find(parent,i*n+j);
                    s[p]++;
                }
            }
        }
        int ma=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                unordered_set<int>st;
                int t=1;
                for(int in=0;in<4;in++){
                    int nr=dr[in]+i;
                    int nc=dc[in]+j;
                    if(isvalid(nr,nc,n) && grid[nr][nc]==1){
                        int p=find(parent,nr*n+nc);
                        if(st.find(p)==st.end()){
                        t+=s[p];
                        st.insert(p);
                    }
                }
            }
            ma=max(ma,t);
        }
        }
        for (int i=0; i<n*n;i++){
            if (parent[i]==i){
                ma=max(ma,s[i]);
            }
        }
        return ma;
    }
};