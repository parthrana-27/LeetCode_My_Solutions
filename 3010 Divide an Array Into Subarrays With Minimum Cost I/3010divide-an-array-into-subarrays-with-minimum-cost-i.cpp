class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        vector<int>suff(n);
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=min(nums[i],suff[i+1]);
        }
        int ans=INT_MAX;
        for(int i=1;i<=n-2;i++){
            ans=min(ans,nums[0]+nums[i]+suff[i+1]);
        }
        return ans;
    }
};