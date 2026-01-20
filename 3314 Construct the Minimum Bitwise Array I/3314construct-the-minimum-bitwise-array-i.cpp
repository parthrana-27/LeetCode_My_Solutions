class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n,-1);

        for (int i=0;i<n;i++) {
            int x=nums[i];

            while(x>=0){
                if((x-1| x) == nums[i]){
                    v[i]=x-1;
                }
                x--;
            }  
        }
        return v;
    }
};