class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int el;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                cnt=1;
                el=nums[i];
            }
            else if(nums[i]==el)
            {
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return el;
    }
};