class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int mi=INT_MAX;
        for(int val:nums){
            int s=0;
            while(val>0){
                s+=(val%10);
                val/=10;
            }
            mi=min(mi,s);
        }
        return mi;
    }
};