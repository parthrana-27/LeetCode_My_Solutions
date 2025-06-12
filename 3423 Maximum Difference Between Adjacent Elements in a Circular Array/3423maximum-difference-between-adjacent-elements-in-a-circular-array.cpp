class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int m=INT_MIN;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            int dif=abs(nums[i-1]-nums[i]);
            m=max(m,dif);
        }
        int l=abs(nums[n-1]-nums[0]);
         m=max(l,m);
        return m;
    }
};