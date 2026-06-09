class Solution {
    private:
    typedef long long ll;
    vector<ll> dijkstra(int n,vector<vector<pair<int,int>>>& adj, int start){
        vector<ll>dist(n,LLONG_MAX);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        dist[start]=0;
        pq.push({0,start});
        while(!pq.empty()){
            ll di=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(di>dist[u]) continue;
            for(auto& e:adj[u]){
                int v=e.first;
                int w=e.second;
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest){
        vector<vector<pair<int,int>>>adj(n),rev(n);
        for(auto& it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            rev[it[1]].push_back({it[0],it[2]});
        }
        vector<ll>dist1=dijkstra(n,adj,src1);
        vector<ll>dist2=dijkstra(n,adj,src2);
        vector<ll>dist3=dijkstra(n,rev,dest);
        ll mi=LLONG_MAX;
        for(int i=0;i<n;i++){
            if(dist1[i]==LLONG_MAX || dist2[i]==LLONG_MAX || dist3[i]==LLONG_MAX) continue;

            ll total=dist1[i]+dist2[i]+dist3[i];
            if(total<mi) mi=total;
        }
        return mi==LLONG_MAX?-1:mi;
    }
};