class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(string s:words){
            int cur=0;
            for(char c:s){
                cur+=weights[c-'a'];
            }
            int rem=cur%26;
            ans+='z'-rem;
        }
        return ans;
    }
};