class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if (n < k) {
            return false;
        }

        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        int oddCount = 0;
        for (auto& [ch, count] : freq) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }

        return oddCount <= k;
    }
};
