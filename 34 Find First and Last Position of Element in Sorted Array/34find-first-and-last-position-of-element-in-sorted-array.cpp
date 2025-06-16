class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        vector<int> result = {-1, -1};        
        int first_pos=-1,second_pos=-1;

        while(left<=right){
            int mid=(left+right)/2;
            if(target==nums[mid]){
                first_pos=mid;
                right=mid-1;
            }else if(target<nums[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        result[0]=first_pos;
        if(first_pos==-1){
            return result;
        }

        left = 0;
        right = nums.size() - 1;

        while(left<=right){
            int mid=(left+right)/2;
            if(target==nums[mid]){
                second_pos=mid;
                left=mid+1;
            }else if(target<nums[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        result[1]=second_pos;
        return result;
    }
};