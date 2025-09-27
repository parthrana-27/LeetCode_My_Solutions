class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> freq;
        unordered_map<int,vector<char>> fg;
        int ma=0;
        int tar=0;
        for (char c:s){
            freq[c]++;
        }
        for (auto &[ch,f]:freq){
            fg[f].push_back(ch);
        }
        for (auto &[f, group] : fg) {
            int size = group.size();
            if (size > ma || (size == ma&& f > tar)) {
                ma = size;
                tar = f;
            }
        }
        string res;
        for (char ch:fg[tar]){
            res+=ch;
        }
        return res;
    }
};
