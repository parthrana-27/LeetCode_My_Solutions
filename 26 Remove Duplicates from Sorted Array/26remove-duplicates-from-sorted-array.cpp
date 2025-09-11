class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0,r=1;
        for(r=1;r<nums.size();r++)
        {
            if(nums[r]!=nums[l])
            {
                l++;
                nums[l]=nums[r];
            }
        }
        return l+1;
    }
};