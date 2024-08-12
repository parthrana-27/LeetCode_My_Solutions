class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        std::vector<int>sub_sum;
        for(int i=0;i<n;i++)
        {
            int cur_sum=0;
            for(int j=i;j<n;j++)
            {
                cur_sum+=nums[j];
                sub_sum.push_back(cur_sum);
            }
        }
        std::sort(sub_sum.begin(),sub_sum.end());

        const int MOD=1e9+7;
        long long result=0;
        for(int i=left-1;i<right;i++)
        {
            result=(result+sub_sum[i])%MOD;
        }
        return result;
    }
};