class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        long long total=0LL;
        for (int x:nums) total+=(long long)x;
        long long cap=total+1LL;
        vector<long long>suf(n+1,1LL);
        suf[n]=1LL;
        for(int i=n-1;i>=0;i--){
            if(suf[i+1]>cap/(long long)nums[i]) suf[i]=cap;
            else suf[i]=suf[i+1]*(long long)nums[i];
        }
        long long pre=0LL;
        for(int i=0;i<n;i++){
            long long r_p=suf[i+1];
            if(pre==r_p) return i;
            pre+=(long long)nums[i];
        }
        return -1;
    }
};