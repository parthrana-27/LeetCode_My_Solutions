class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        int n=s.size();
        string ma="";
        string mi="";
        char ele=' ';

        for(int i=0;i<n;i++)
        {
            if(s[i]!='9')
            {
                ele=s[i];
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ele==s[i])ma+='9';
            else ma+=s[i];
        }
        for(int i=0;i<n;i++)
        {
            if(s[0]==s[i])mi+='0';
            else mi += s[i];
        }
        return stoi(ma)-stoi(mi);
    }
};