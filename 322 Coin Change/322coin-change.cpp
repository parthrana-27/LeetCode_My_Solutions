class Solution {
public:
    int coinChange(vector<int>& coins, int a) {
        int n = coins.size();
        vector<int> prev(a + 1, INT_MAX);

        // Base case: using only coins[0]
        for (int i = 0; i <= a; i++) {
            if (i % coins[0] == 0) prev[i] = i / coins[0];
        }

        for (int i = 1; i < n; i++) {
            vector<int> cur(a + 1, INT_MAX);
            for (int j = 0; j <= a; j++) {
                int not_take = prev[j];
                int take = INT_MAX;
                if (coins[i] <= j && cur[j - coins[i]] != INT_MAX)
                    take = 1 + cur[j - coins[i]];
                cur[j] = min(take, not_take);
            }
            prev = cur;
        }

        return prev[a] == INT_MAX ? -1 : prev[a];
    }
};
