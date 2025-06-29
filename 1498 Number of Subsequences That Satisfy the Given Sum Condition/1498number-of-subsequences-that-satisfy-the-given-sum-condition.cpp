class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod=1e9+7;
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        vector<int>p(n,1);
        for(int i=1;i<n;i++){
            p[i]=(p[i-1]*2)%mod;
        }
        int l=0,r=n-1,res=0;
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                res=(res+p[r-l])%mod;
                ++l;
            }else{
                --r;
            }
        }
        return res;
    }
};