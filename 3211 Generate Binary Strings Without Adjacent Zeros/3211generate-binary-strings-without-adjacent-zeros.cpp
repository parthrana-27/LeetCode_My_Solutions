class Solution {
public:
    void dfs(int n, string& curr, vector<string>& res) {
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }
        curr.push_back('1');
        dfs(n, curr, res);
        curr.pop_back();

        if (curr.empty() || curr.back() != '0') {
            curr.push_back('0');
            dfs(n, curr, res);
            curr.pop_back();
        }
    }
    vector<string> validStrings(int n) {
       vector<string> res;
        string curr;
        dfs(n,curr,res);
        return res;
    }
};