class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        for(int s=n;s>1;s--)
        {
            for(int i=0;i<s-1;i++)
            {
                nums[i]=(nums[i]+nums[i+1])%10;
            }
        }
        return nums[0];
    }
};