class Solution {
    private:
    int f(vector<int>&nums,int s,int e){
        int prev2=0,prev1=0;
        for(int i=s;i<=e;i++){
            int cur=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int ans=max(f(nums,0,n-2),f(nums,1,n-1));
        return ans;
    }
};