class Solution {
public:
    vector<int> rotateElements(vector<int>& nums,int k){
        vector<int>pos;
        for(int num:nums){
            if(num >= 0) pos.push_back(num);
        }
        int n=pos.size();
        if(n==0) return nums;
        k%=n;
        vector<int>rot(n);
        for(int i=0;i<n;i++){
            rot[i]=pos[(i+k)%n];
        }
        int idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                nums[i]=rot[idx++];
            }
        }
        return nums;
    }
};