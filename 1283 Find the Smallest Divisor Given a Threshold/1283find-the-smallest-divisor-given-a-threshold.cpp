class Solution {
    private:
    bool pos(int mid,vector<int>&arr,int t){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=(arr[i]+mid-1)/mid;
        }
        return sum<=t;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ma=INT_MIN;
        for(int i=0;i<nums.size();i++){
            ma=max(ma,nums[i]);
        }
        int l=1,r=ma;
        int ans=ma;
        while(l<=r){
            int mid=(l+r)/2;
            if(pos(mid,nums,threshold)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};