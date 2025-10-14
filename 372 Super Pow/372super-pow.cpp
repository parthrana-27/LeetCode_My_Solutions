class Solution {
public:
    int mod = 1337;

    int m(int a, int k) {
        a %= mod;
        int res = 1;
        while (k > 0) {
            if (k % 2 == 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            k /= 2;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int l = b.back();
        b.pop_back();
        int p1 = m(a, l);
        int p2 = m(superPow(a, b), 10);
        return (p1 * p2) % mod;
    }
};
