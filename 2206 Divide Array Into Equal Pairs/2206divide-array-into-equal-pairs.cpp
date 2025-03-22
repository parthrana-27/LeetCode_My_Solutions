class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        int want=n/2;
        vector<int>freq(501,0);
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        for(int i=0;i<freq.size();i++)
        {
            if(freq[i]%2!=0)
            {
                return false;
            }
        }
        return true;
    }
};