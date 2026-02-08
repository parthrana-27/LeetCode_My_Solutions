class Solution {
public:
    int dominantIndices(vector<int>& nums) {
       int n=nums.size();
        vector<int>pref(n);
        pref[n-1]=0;
        for(int i=n-2;i>=0;i--){
            pref[i]=pref[i+1]+nums[i+1];
        }
        int c=0;
        for(int i=0;i<n-1;i++){
            long long sum=pref[i];
            int len=n-i-1;
            double avg=(double)sum/len;
            if(nums[i]>avg) c++;
        }
        return c;
    }
};