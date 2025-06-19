class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>ins(200,0);
        vector<int>in(200,0);
        int len=s.length();
        if(len!=t.length()) return false;
        for(int i=0;i<len;i++)
        {
            if(ins[s[i]] != in[t[i]]){
                return false;
            }
            ins[s[i]]=i+1;
            in[t[i]]=i+1;
        }
        return true;
    }
};