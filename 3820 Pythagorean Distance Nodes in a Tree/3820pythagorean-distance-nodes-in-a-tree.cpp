class Solution {
    private:
    vector<int>bfs(int s,int n,vector<vector<int>>& adj){
        vector<int>dis(n,-1);
        queue<int>q;
        q.push(s);
        dis[s]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int v:adj[node]){
                if(dis[v]==-1){
                    dis[v]=dis[node]+1;
                    q.push(v);
                }
            }
        }
        return dis;
    }
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>>adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>dx=bfs(x,n,adj);
        vector<int>dy=bfs(y,n,adj);
        vector<int>dz=bfs(z,n,adj);
        int cnt=0;
        for(int i=0;i<n;i++){
            vector<int>d={dx[i],dy[i],dz[i]};
            sort(d.begin(),d.end());
            long long a=d[0],b=d[1],c=d[2];
            if((a*a+b*b)==c*c){
               cnt++; 
            }
        }
        return cnt;
    }
};