class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        int total=0;
        for(int num:nums){
            total+=num;
        }
        int left=0;
        for(int i=0;i<n;i++){
            int right=total-left-nums[i];
            res[i]=abs(left-right);
            left+=nums[i];
        }
        return res;
    }
};