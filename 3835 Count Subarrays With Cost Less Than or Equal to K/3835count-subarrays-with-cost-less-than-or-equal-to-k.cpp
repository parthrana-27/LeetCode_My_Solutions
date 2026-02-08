class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k){
        int n=nums.size();
        int l=0;
        long long ans=0;
        deque<int>maq,miq;
        for(int r=0;r<n;r++){
            while(!maq.empty() && nums[maq.back()]<=nums[r]) maq.pop_back();
            maq.push_back(r);
            while(!miq.empty() && nums[miq.back()]>=nums[r]) miq.pop_back();
            miq.push_back(r);
            while(l<=r){
                long long ma=nums[maq.front()];
                long long mi=nums[miq.front()];
                long long cost=(ma-mi)*1LL*(r-l+1);
                if(cost<=k) break;
                if(maq.front()==l) maq.pop_front();
                if(miq.front()==l) miq.pop_front();
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
};