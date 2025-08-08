#include <bits/stdc++.h>
using namespace std;

class Solution {
    double dp[201][201];

    double dfs(int a, int b) {
        if (a <= 0 && b >0) return 1.0;
        if (a <= 0 && b <= 0) return 0.5;
        if (a > 0 && b <= 0) return 0.0;

        if (dp[a][b] >= 0) return dp[a][b];

        return dp[a][b] = 0.25 *(
            dfs(a - 4, b) +
            dfs(a - 3, b - 1) +
            dfs(a - 2, b - 2) +
            dfs(a - 1, b - 3)
        );
    }

public:
    double soupServings(int n) {
        if (n > 5000) return 1.0;
        int N = ceil(n / 25.0);
        memset(dp, -1, sizeof(dp));

        return dfs(N, N);
    }
};
