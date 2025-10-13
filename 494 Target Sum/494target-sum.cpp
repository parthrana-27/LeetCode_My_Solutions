class Solution {
public:
      int findTargetSumWays(vector<int>& nums, int target){
        int total=accumulate(nums.begin(),nums.end(),0);
        if((total+target)%2!= 0||abs(target)>total) return 0;
        int tar=(total+target)/2;
        int n =nums.size();
        vector<int>dp(tar+1,0);
        dp[0]=1;
        for (int i:nums){
            for (int j=tar;j>=i;--j) {
                dp[j]+=dp[j-i];
            }
        }
        return dp[tar];
    }
};