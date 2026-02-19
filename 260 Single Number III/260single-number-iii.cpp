class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int xorr=0;
        for(int i=0;i<n;i++) xorr=xorr^nums[i];
        int r = 1;
        while((xorr&r)==0){
             r<<=1;
        }
        int b1=0,b2=0;
        for(int i=0;i<n;i++){
            if(nums[i]&r) b1^=nums[i];
            else b2^=nums[i];
        }
        return {b1,b2};
    }
};