class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int ma=*max_element(nums.begin(),nums.end());
        int mi=*min_element(nums.begin(),nums.end());
        long long ans=1LL*(ma-mi)*k;
        return ans;
    }
};