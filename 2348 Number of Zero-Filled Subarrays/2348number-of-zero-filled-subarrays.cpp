class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c=0;
        long long cur=0;
        for(long long i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                cur++;
                c+=cur;
            }else {
                cur=0;
            }
        }
        return c;
    }
};