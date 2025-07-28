class Solution {
public:
int cou(vector<int>& arr,int g)
{
    if(g<0) return 0;
        int l=0,r=0,c=0;
        int sum=0;
        while(r<arr.size())
        {
            sum+=(arr[r]%2);
            while(sum>g)
            {
                sum-=(arr[l]%2);
                l++;
            }
            c+=(r-l+1);
            r++;
        }
        return c;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return cou(nums,k)-cou(nums,k-1);
    }
};