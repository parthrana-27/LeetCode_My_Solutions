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
    int removeStones(vector<vector<int>>& stones){
        int mr=0;
        int mc=0;
        for(auto it:stones){
            mr=max(mr,it[0]);
            mc=max(mc,it[1]);
        }
        int t=mc+mr+2;
        vector<int>parent(t),rank(t,0);
        iota(parent.begin(),parent.end(),0);
        for(auto& it:stones) unionSet(parent,rank,it[0],it[1]+mr+1);
        unordered_set<int>roots;
        for(auto& it:stones){
            roots.insert(find(parent,it[0]));
        }
        return stones.size()-roots.size();
    }
};