class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>=nums[l]){
                ans=min(nums[l],ans);
                l=mid+1;
            }else{
                r=mid-1;
                ans=min(ans,nums[mid]);
            }
        }
        return ans;
    }
};