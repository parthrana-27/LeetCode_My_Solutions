class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
         if(n%k!=0) return false;
        unordered_map<int,int>freq;
        for(int num:nums)
            {
                freq[num]++;
            }
        int maxfreq=0;
        for(auto &p:freq)
            {
                maxfreq=max(maxfreq,p.second);
            }
        return maxfreq <=n/k;
    }
};