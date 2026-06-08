class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int i=0,j=n-1;
        vector<int>res(n);
        while(i<n){
            if(nums[i]<pivot){
                res[l++]=nums[i];
            }
            if(nums[j]>pivot){
                res[r--]=nums[j];
            }
            i++;
            j--;
        }
        while(l<=r){
            res[l++]=pivot;
        }
        return res;
    }
};