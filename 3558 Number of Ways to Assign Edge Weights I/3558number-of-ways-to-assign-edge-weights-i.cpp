class Solution {
    private:
    int mod=1e9+7;
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto& it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>dep(n+1,-1);
        dep[1]=0;
        queue<int>q;
        q.push(1);
        int ma=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ma=max(ma,dep[u]);
            for(int v:adj[u]){
                if(dep[v]==-1){
                    dep[v]=dep[u]+1;
                    q.push(v);
                }
            }
        }
        int ans=1;
        int base=2;
        int exp=ma-1;
        while(exp>0){
            if(exp&1) ans=(1LL*ans*base)%mod;
            base=(1LL*base*base)%mod;
            exp>>=1;
        }
        return ans;
    }
};