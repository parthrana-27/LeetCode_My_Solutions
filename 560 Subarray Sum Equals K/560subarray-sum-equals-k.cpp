class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        map<int,int>mp;
        mp[0]=1;
        int pre=0;
        for(int i=0;i<n;i++)
        {
            pre+=nums[i];
            int remove=pre-k;
            count+=mp[remove];
            mp[pre]++;
        }
        return count;
    }
};