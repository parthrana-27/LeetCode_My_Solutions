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
public:
    int makeConnected(int n, vector<vector<int>>& con){
        if(con.size()<n-1) return -1;
        vector<int>parent(n),rank(n,0);
        iota(parent.begin(),parent.end(),0);
        for(auto& c:con){
            unionSet(parent,rank,c[0],c[1]);
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(find(parent,i)==i){
                comp++;
            }
        }
        return comp-1;
    }
};