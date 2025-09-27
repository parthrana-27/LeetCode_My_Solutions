class Solution {
public:
    pair<int, int> sim(const string& s) {
        int x = 0, y = 0;
        for (char move : s) {
            if (move == 'U') y++;
            else if (move == 'D') y--;
            else if (move == 'L') x--;
            else if (move == 'R') x++;
        }
        return {x, y};
    }

    int distinctPoints(string s, int k) {
        int n = s.size();
        vector<pair<int, int>> prefix(n + 1), suffix(n + 1);

        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i];
            if (s[i] == 'U') prefix[i + 1].second++;
            else if (s[i] == 'D') prefix[i + 1].second--;
            else if (s[i] == 'L') prefix[i + 1].first--;
            else if (s[i] == 'R') prefix[i + 1].first++;
        }

        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1];
            if (s[i] == 'U') suffix[i].second++;
            else if (s[i] == 'D') suffix[i].second--;
            else if (s[i] == 'L') suffix[i].first--;
            else if (s[i] == 'R') suffix[i].first++;
        }
        unordered_set<string> uni;
        for (int i = 0; i <= n - k; ++i) {
            int x = prefix[i].first + suffix[i + k].first;
            int y = prefix[i].second + suffix[i + k].second;
            uni.insert(to_string(x) + "," + to_string(y));
        }

        return uni.size();
    }
};
