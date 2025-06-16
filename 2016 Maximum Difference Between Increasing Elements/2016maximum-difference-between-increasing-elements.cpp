class Solution {
public:
    int maximumDifference(vector<int>& nums) {
       int diff=-1;
       int mn=nums[0];
       int n=nums.size();
       for(int i=1;i<n;i++)
       {
        if(nums[i]>mn)
        {
            diff=max(nums[i]-mn,diff);
        }
        if(nums[i]<mn){
            mn=nums[i];
        }
       }
       return diff;
    }
};