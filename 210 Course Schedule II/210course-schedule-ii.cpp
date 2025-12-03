class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&order){
        vis[node]=1;
        for(int nei:adj[node]){
            if(vis[nei]==0){
                if(!dfs(nei,adj,vis,order)){
                    return false;
                }
            }
                else if(vis[nei]==1){
                    return false;
                }
        }
            vis[node]=2;order.push_back(node);
            return true;
    }
    vector<int> findOrder(int numc, vector<vector<int>>& pre) {
        vector<vector<int>>adj(numc);
        for(auto& p:pre){
            adj[p[1]].push_back(p[0]);
        }
        vector<int>vis(numc,0);
        vector<int>order;
        for(int i=0;i<numc;i++){
            if(vis[i]==0){
                if(!dfs(i,adj,vis,order)){
                    return {};
                }
            }
        }
        reverse(order.begin(),order.end());
        return order;
    }
};