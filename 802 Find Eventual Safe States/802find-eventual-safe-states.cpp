class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<vector<int>>adjrev(v);
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto it:graph[i]){
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        vector<int>safe;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe.push_back(node);
            for(auto it:adjrev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};