class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int sum=nums[l]+nums[r];
            if(sum==tar) return {l+1,r+1};
            else if(sum>tar)r--;
            else l++;
        }
        return {};
    }
};