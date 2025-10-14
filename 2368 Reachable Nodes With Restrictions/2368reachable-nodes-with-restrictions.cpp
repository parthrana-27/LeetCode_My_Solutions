class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>graph(n);
        for (auto& e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        unordered_set<int>banned(restricted.begin(), restricted.end());
        vector<bool>visited(n, false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        int count=0;
        while (!q.empty()){
            int node=q.front(); 
            q.pop();
            count++;
            for (int nei:graph[node]){
                if(!visited[nei] && !banned.count(nei)){
                    visited[nei]=true;
                    q.push(nei);
                }
            }
        }
        return count;
    }
};
