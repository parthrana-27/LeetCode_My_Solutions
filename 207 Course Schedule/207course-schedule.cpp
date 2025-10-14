class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(n);
        for(auto& p:prerequisites){
            g[p[1]].push_back(p[0]);
        }
         vector<int> visited(n, 0); 

        function<bool(int)> dfs = [&](int node) {
            if (visited[node]==1) return false; 
            if (visited[node]==2) return true;  

            visited[node]=1;
            for (int nei : g[node]) if (!dfs(nei)) return false;
            visited[node]=2;
            return true;
        };

        for(int i=0;i<n;++i)
            if (!dfs(i)) return false;
        return true;
    }
};