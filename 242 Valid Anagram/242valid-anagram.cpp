class Solution {
public:
    bool isAnagram(string s, string t) {
        int c1[256],c2[256];
        for(char ch:s)
        {
            c1[ch]++;
        }
        for(char ch:t)
        {
            c2[ch]++;
        }
        for(int i=0;i<256;i++)
        {
            if(c1[i]!=c2[i])
            {
                return false;
            }
        }
        return true;
    }
};