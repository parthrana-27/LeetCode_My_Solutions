class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lsum=0,rsum=0,ma=0;
        int n=nums.size();
        int r=n-1;
        for(int i=0;i<k;i++){lsum+=nums[i];
        ma=lsum;}
        for(int i=k-1;i>=0;i--)
        {
            lsum-=nums[i];
            rsum+=nums[r--];
            ma=max(ma,lsum+rsum);
        }
        return ma;
    }
};