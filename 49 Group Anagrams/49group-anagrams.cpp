class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string,vector<string>>grp;
        for(string& s:strs){
            string key=s;
            sort(key.begin(),key.end());
            grp[key].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto& it:grp){
            ans.push_back(it.second);
        }
        return ans;
    }
};