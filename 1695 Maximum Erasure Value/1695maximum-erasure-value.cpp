class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l=0;
        int r=0;
        int cur=0;
        int ans=0;
        unordered_set<int>st;
        int n=nums.size();
        for(r=0;r<n;r++)
        {
           while (st.count(nums[r]))
           {
            st.erase(nums[l]);
            cur-=nums[l];
            l++;
           }
            st.insert(nums[r]);
            cur+=nums[r];
            ans=max(ans,cur);
        }
        return ans;
    }
};