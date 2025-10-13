class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        string prev="";
        for(string word:words){
            string s=word;
            sort(s.begin(),s.end());
            if(s!=prev)
            {
                ans.push_back(word);
                prev=s;
            }
        }
        return ans;
    }
};