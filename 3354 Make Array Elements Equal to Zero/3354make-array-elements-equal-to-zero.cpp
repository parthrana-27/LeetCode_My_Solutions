class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int s=0;
        int cur=0; 
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        for(int num:nums){
            int right=s-left-num;
            if(num==0){
                if(left==right){
                    cur+=2;
                }else if(left==right-1 || left-1==right){
                    cur++;
                }
            }
            left+=num;
        }
        return cur;
    }
};