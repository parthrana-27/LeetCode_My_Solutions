#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> supplySet(supplies.begin(), supplies.end());
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> adj;
        queue<string> q;
        vector<string> ans;

        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size();
            for (const string& ing : ingredients[i]) {
                adj[ing].push_back(recipes[i]);
            }
        }

        for (const string& supply : supplies) {
            q.push(supply);
        }

        while (!q.empty()) {
            string item = q.front();
            q.pop();

            if (inDegree.find(item) != inDegree.end()) {
                ans.push_back(item);
            }

            for (const string& recipe : adj[item]) {
                if (--inDegree[recipe] == 0) {
                    q.push(recipe);
                }
            }
        }

        return ans;
    }
};
