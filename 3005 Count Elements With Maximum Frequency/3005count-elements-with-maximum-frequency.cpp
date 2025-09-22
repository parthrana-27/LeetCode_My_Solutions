class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101]={0};
        int m=0,f=0;
        for(int n:nums)
        {
            f+=(++freq[n]==m);
            if(freq[n]>m) f=1,m=freq[n];
        }
        return f*m;
    }
};