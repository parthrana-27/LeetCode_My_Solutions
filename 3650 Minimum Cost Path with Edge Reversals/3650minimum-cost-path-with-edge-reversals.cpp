class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>>adj(n),incoming(n);
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
            incoming[v].push_back({u,w});
        }
        using ll=long long;
        const ll INF=1e18;

        vector<vector<ll>>dist(n,vector<ll>(2, INF));
        dist[0][0]=0;

        using T=tuple<ll,int,int>;
        priority_queue<T,vector<T>,greater<T>> pq;
        pq.push({0,0,0});

        while(!pq.empty()){
            auto [d,u,state]=pq.top();
            pq.pop();
            if(d>dist[u][state]) continue;

            for(auto &[v,w]:adj[u]){
                if(d+w < dist[v][0]){
                    dist[v][0]=d+w;
                    pq.push({dist[v][0],v,0});
                }
            }
            if(state==0){
                for(auto &[v,w]:incoming[u]){
                    ll cost=2LL*w;
                    if(d + cost<dist[v][0]){
                        dist[v][0]=d+cost;
                        pq.push({dist[v][0],v,0});
                    }
                }
            }
        }
        ll ans=min(dist[n-1][0],dist[n-1][1]);
        return ans==INF?-1:ans;
    }
};
