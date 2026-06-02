class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int closest=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int cur=nums[i]+nums[l]+nums[r];
                if(abs(cur-target)<abs(closest-target)){
                    closest=cur;
                }
                if(cur<target) l++;
                else r--;
            }
        }
        return closest;
    }
};