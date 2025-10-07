class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        auto getSums = [&](vector<int>& arr) {
            int m = arr.size();
            vector<vector<int>> res(m + 1);
            for (int mask = 0; mask < (1 << m); ++mask) {
                int sum = 0, cnt = 0;
                for (int i = 0; i < m; ++i) {
                    if (mask & (1 << i)) sum += arr[i], cnt++;
                }
                res[cnt].push_back(sum);
            }
            return res;
        };

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        auto L = getSums(left);
        auto R = getSums(right);
        for (auto& v : R) sort(v.begin(), v.end());

        int ans = INT_MAX;
        for (int k = 0; k <= n; ++k) {
            for (int x : L[k]) {
                int target = total / 2 - x;
                auto& vec = R[n - k];
                auto it = lower_bound(vec.begin(), vec.end(), target);
                if (it != vec.end())
                    ans = min(ans, abs(total - 2 * (x + *it)));
                if (it != vec.begin())
                    ans = min(ans, abs(total - 2 * (x + *prev(it))));
            }
        }
        return ans;
    }
};
