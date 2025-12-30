class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int ma=0;
        for(int i=0;i<n;i++){
            if(i>ma) return false;
            ma=max(ma,i+nums[i]);
        }
        return true;
    }
};