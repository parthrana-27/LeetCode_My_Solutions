class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& can, int target, int start, vector<int>& path) {
        if (target == 0) {  
            ans.push_back(path);  
            return;
        }
        for (int i = start; i < can.size(); i++) {
            if (can[i] > target) continue;  
            path.push_back(can[i]);        
            backtrack(can, target - can[i], i, path);
            path.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<int> path;
        backtrack(can, target, 0, path);
        return ans;
    }
};
