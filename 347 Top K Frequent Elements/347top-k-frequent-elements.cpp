class Solution {
public:
    vector<int>topKFrequent(vector<int>& nums, int k){
        // {freq,num}
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int v:nums){
            mp[v]++;
        }
        for(auto [v,f]:mp){
            pq.push({f,v});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            auto it=pq.top();
            ans.push_back(it.second);
            pq.pop();
        }
        return ans;
    }
};