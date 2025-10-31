class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>freq;
        for(int i:nums){
            freq[i]++;
        }
        for(auto a:freq){
            if(a.second > 1){
                ans.push_back(a.first);
            }
        }
        return ans;
    }
};