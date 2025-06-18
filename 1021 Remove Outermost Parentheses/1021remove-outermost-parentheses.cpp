class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int b=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(b>0)
                {
                    res+=s[i];
                }
                b++;
            }else{
                b--;
                if(b>0){
                    res+=s[i];
                }
            }
        }
        return res;
    }
};