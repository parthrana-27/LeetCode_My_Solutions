class Solution {
    private:
    void merge(vector<int>& nums,int l,int m,int h){
        vector<int>sorted;
        int left=l;
        int right=m+1;
        while(left<=m && right<=h){
            if(nums[left]<=nums[right]){
                sorted.push_back(nums[left]);
                left++;
            }else{
                sorted.push_back(nums[right]);
                right++;
            }
        }
        while(left<=m){
            sorted.push_back(nums[left]);
            left++;
        }
        while(right<=h){
            sorted.push_back(nums[right]);
            right++;
        }
        for(int i=l;i<=h;i++){
            nums[i]=sorted[i-l];
        }
    }
    void mergeSort(vector<int>& nums,int l,int h){
        if(l>=h) return;
        int mid=l+(h-l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,h);
        merge(nums,l,mid,h);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};