class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n);
        vector<int>suff(n);
        pref[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1],nums[i]);
        }
        for(int i=n-2;i>0;i--){
            suff[i]=min(suff[i+1],nums[i]);
        }
        vector<int>ans(n);
        int c=0;
        for(int i=0;i<n;i++){
            if(i==n-1|| pref[i]<=suff[i+1]){
            int r=0;
            for(int k=c;k<=i;k++){
                r=max(r,nums[k]);
            }
            for(int k=c;k<=i;k++){
                ans[k]=r;
            }
            c=i+1;
            }
        }
        return ans;
    }
};