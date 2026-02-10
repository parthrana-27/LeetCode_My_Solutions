class Solution {
    private:
    typedef priority_queue<string,vector<string>,greater<string>> pq;
    void dfs(string s,unordered_map<string,pq> &adj,vector<string> &ans){
        while(!adj[s].empty()){
            string nei=adj[s].top();
            adj[s].pop();
            dfs(nei,adj,ans);
        }
        ans.push_back(s);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,pq>adj;
        for(auto it:tickets){
            adj[it[0]].push(it[1]);
        }
        vector<string>ans;
        dfs("JFK",adj,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};