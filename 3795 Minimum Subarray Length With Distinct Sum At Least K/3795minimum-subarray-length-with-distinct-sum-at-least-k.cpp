class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        int l=0,r=0;
        int sum=0;
        int ans=INT_MAX;
        for(int r=0;r<n;r++){
            if(freq[nums[r]]==0){
            sum+=nums[r];
            }
            freq[nums[r]]++;
            while(sum >=k){
                ans=min(ans,r-l+1);
                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                    sum-=nums[l];
                }
                l++;
            }
        }
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};