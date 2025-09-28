class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();

        vector<long long> pref(n),suff(n);
        vector<bool> inc(n), dec(n);

        pref[0]=nums[0];
        inc[0]=true;
        for (int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
            inc[i]=inc[i-1] && (nums[i]>nums[i-1]);
        }

        suff[n-1]=nums[n-1];
        dec[n-1]=true;
        for (int i = n-2;i>=0;i--){
            suff[i]=suff[i+1]+nums[i];
            dec[i]=dec[i+1]&&(nums[i]>nums[i+1]);
        }
        long long ans=LLONG_MAX;
        for(int i=0;i<n-1;i++){
            if(inc[i]&&dec[i+1]){
                ans = min(ans,llabs(pref[i]-suff[i+1]));
            }
        }
        return (ans==LLONG_MAX?-1:ans);
    }
};
