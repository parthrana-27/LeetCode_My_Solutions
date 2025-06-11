class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        int f_max=*max_element(nums.begin(),nums.end());
        int s_max=INT_MIN;
        int t_max=INT_MIN;
        int c1=0;
        for(int i=0;i<nums.size();i++)
        {
            if(s_max<nums[i] && nums[i]!=f_max)
            {
                s_max=nums[i];
                c1++;
            }
        }
        if(c1==0) return f_max;
        int c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if((t_max<nums[i] || nums[i]==INT_MIN) && (nums[i] != f_max && nums[i] != s_max))
            {
                t_max=nums[i];
                c2++;
            }
        }
        if(c2>0)
        {
            return t_max;
        }else{
            return f_max;
        }

    }
};