class Solution {
public:
    bool checkValidString(string s) {
       int mi=0,ma=0;
       for(int i=0;i<s.length();i++)
       {
            if(s[i]=='('){

                mi++;
                ma++;
            }
            else if(s[i]==')')
            {
                mi--;
                ma--;
            }
            else{
                mi--;
                ma++;
            }
            if(mi<0)mi=0;
            if(ma<0) return false;
       }
       return (mi==0);
    }
};