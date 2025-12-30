class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        int r=1;
        while(!pq.empty()){
            int val=pq.top();
            pq.pop();
            if(mp.find(val) == mp.end()){
                mp[val]=r++;
            }
        }
        vector<int>ans;
        for(int v:arr){
            ans.push_back(mp[v]);
        }
        return ans;
    }
};