class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            int tar=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target){
                    tar++;
                }
                int l=j-i+1;
                if(tar>l/2) c++;
            }
        }
        return c;
    }
};