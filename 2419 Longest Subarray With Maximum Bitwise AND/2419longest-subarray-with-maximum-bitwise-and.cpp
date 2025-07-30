class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ma_element=*max_element(nums.begin(),nums.end());
        int c=0,ma=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ma_element)
            {
                c++;
                ma=max(ma,c);
            }
            else c=0;
        }
        return ma;
    }
};