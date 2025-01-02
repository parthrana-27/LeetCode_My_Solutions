int countPairs(int* nums, int numsSize, int target) {
    int n=numsSize;
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            int sum=nums[i]+nums[j];
            if(sum<target)
            {
                count++;
            }
        }
    }
    return count;
}