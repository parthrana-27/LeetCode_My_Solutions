class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        unordered_map<int,int>c;
        for(auto it:freq){
            c[it.second]++;
        }
        for(int i=0;i<n;i++){
            if(c[freq[nums[i]]]==1){
                 return nums[i];
            }
        }
        return -1;
    }
};