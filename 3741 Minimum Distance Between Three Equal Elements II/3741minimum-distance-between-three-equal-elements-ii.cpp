class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return -1;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto& [val,idxs]:mp){
            if(idxs.size()<3) continue;
            for(int i=0;i+2<idxs.size();i++){
                int dist=2*(idxs[i+2]-idxs[i]);
                ans=min(ans,dist);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};