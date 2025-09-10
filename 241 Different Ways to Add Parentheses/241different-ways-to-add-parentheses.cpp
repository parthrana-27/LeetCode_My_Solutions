class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression)) return memo[expression];
        
        vector<int> results;
        
        for (int i = 0; i < expression.size(); i++) {
            char ch = expression[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                
                for (int l : left) {
                    for (int r : right) {
                        if (ch == '+') results.push_back(l + r);
                        else if (ch == '-') results.push_back(l - r);
                        else if (ch == '*') results.push_back(l * r);
                    }
                }
            }
        }
        
        if (results.empty()) {
            results.push_back(stoi(expression));
        }
        
        memo[expression] = results;
        return results;
    }
};