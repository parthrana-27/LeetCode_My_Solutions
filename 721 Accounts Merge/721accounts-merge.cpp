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
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        vector<int>parent(n),rank(n,0);
        iota(parent.begin(),parent.end(),0);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<acc[i].size();j++){
                string mail=acc[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }else{
                    unionSet(parent,rank,i,mp[mail]);
                }
            }
        }
        unordered_map<int,set<string>>groups;
        for(auto it:mp){
            groups[find(parent,it.second)].insert(it.first);
        }
        vector<vector<string>>res;
        for(auto it:groups){
            int root=it.first;
            vector<string> merged;
            merged.push_back(acc[root][0]);
            merged.insert(merged.end(), it.second.begin(), it.second.end());

            res.push_back(merged);
        }
        return res;
    }
};