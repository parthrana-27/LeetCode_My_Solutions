class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool neg=true;
        int ma=INT_MIN;
        for(int n:nums)
        {
            if(n>0) neg=false;
            if(n>ma)ma=n;
        }
        if(neg) return ma;
        unordered_set<int>uni(nums.begin(),nums.end());
        int sum=0;
        for(int val:uni){
            if(val>0) sum+=val;
        }
        return sum;
    }
};
