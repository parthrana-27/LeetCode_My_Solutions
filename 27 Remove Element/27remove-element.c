int removeElement(int* nums, int numsSize, int val) {
    int n=numsSize;
    int in=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]!=val)
        {
            nums[in]=nums[i];
            in++;
        }
    }
    return in;
}