class Solution {
public:
int cou(vector<int>& arr,int g)
{
    if(g<0) return 0;
        int l=0,r=0,c=0;
        int sum=0;
        while(r<arr.size())
        {
            sum+=arr[r];
            while(sum>g)
            {
                sum-=arr[l];
                l++;
            }
            c+=(r-l+1);
            r++;
        }
        return c;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       int a= cou(nums,goal);
       int b= cou(nums,goal-1);
       return a-b;
    }
};