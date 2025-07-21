class Solution {
public:
    string makeFancyString(string s) {
        string res="";
        int n=s.length();
        int i=0;
        for(i=0;i<n-2;i++)
        {
            if(s[i]==s[i+1] && s[i]==s[i+2]) continue;
            else res+=s[i];
        }
        while(i<n)
        {
            res+=s[i];
            i++;
        }
        return res;
    }
};