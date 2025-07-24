class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int n=nums.size();
        int zeros=0;
        int ma=0;
        int cur=0;
        while(r<n)
        {
           if(nums[r]==0) zeros++;
           if(zeros>k){
            if(nums[l]==0) zeros--;
            l++;
           }
           if(zeros<=k)cur=r-l+1;
           ma=max(ma,cur);
           r++;
        }
        return ma;
    }
};