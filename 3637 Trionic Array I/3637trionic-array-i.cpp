class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int inc=0,dec=0,inc2=0;
        if(n==3) return false;
        for(int i=1;i<n;i++)
            {
                if(nums[i]==nums[i-1]) return false;
                if(nums[i]<nums[i-1] && inc==0) return false;
                else if(inc2 !=0 && nums[i]<nums[i-1]) return false;
                else if(inc!=0 && nums[i]<nums[i-1]){
                    dec++;}
                
                else if(inc !=0 && dec != 0 && nums[i]>nums[i-1]) inc2++;
                else inc++;
            }
        if(inc && dec && inc2) return true;
        else return false;
    }
};