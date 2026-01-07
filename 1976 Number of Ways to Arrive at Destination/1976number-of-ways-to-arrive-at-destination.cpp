class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,int>>>adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
      priority_queue<pair<long long,int>,vector<pair<long long,int>>,
            greater<pair<long long,int>>>pq;
            vector<long long>dist(n,LLONG_MAX),ways(n,0);
            dist[0]=0;
            ways[0]=1;
            pq.push({0,0});
            int mod=1e9+7;
            while(!pq.empty()){
                long long dis=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto it:adj[node]){
                    int ad=it.first;
                    int edn=it.second;
                    if(dis+edn < dist[ad]){
                        dist[ad]=dis+edn;
                        pq.push({dis+edn,ad});
                        ways[ad]=ways[node];
                    }
                    else if(dis+edn == dist[ad]){
                        ways[ad]=(ways[ad]+ways[node])%mod;
                    }
                }
            }
            return ways[n-1]%mod;
    }
};