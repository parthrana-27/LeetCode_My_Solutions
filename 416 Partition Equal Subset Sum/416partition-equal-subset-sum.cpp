class Solution {
public:
  
    bool sub(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<bool> prev(sum+1,false),cur(sum+1,false);
        prev[0]=cur[0]=true;
        if(arr[0]<=sum) prev[arr[0]]=true;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                bool not_take=prev[j];
                bool take=false;
                if(arr[i]<=j) take =prev[j-arr[i]];
                cur[j] = take||not_take;
            }
            prev = cur;
        }
        
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int t_sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++) t_sum+=nums[i];
        if(t_sum%2==1) return false;
        int tar=t_sum/2;
        return sub(nums,tar);
    }
};