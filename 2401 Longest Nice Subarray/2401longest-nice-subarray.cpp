class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
       int m=1;
       int l=0;
       int used=0;
       for(int r=0;r<n;r++)
       {
        while((used & nums[r])!=0)
        {
            used ^= nums[l];
            ++l;
        }
        used |=nums[r];
        m=max(m,r-l+1);
       }
       return m;
    }
};