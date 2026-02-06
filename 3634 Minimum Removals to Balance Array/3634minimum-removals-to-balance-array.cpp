class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=n;
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n && nums[j]<=1LL*nums[i]*k){
                j++;
            }
            int len=j-i;
            ans=min(n-len,ans);
        }
        return ans;
    }
};