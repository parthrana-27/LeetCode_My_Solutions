class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int v:arr){
            mp[v]++;
        }
        unordered_set<int>uni;
        for(auto& it:mp){
            uni.insert(it.second);
        }
        return uni.size()==mp.size();
    }
};