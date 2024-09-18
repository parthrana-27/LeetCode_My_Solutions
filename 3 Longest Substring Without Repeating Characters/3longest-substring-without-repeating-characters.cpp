class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len=s.length();
        unordered_map<char,int>chindex;
        int m=0;
        int start=0;
        for(int i=0;i<len;i++)
        {
            if(chindex.find(s[i])!=chindex.end())
            {
                   start = max(start, chindex[s[i]] + 1);
            }
            chindex[s[i]]=i;
            m=max(m,i-start+1);
        }
        return m;
    }
};