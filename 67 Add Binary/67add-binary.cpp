class Solution {
public:
    string addBinary(string a, string b) {
        int c=0;
        string r;
        int i=a.size()-1;
        int j=b.size()-1;
        while(i>=0 || j>=0 || c){
            if(i>=0) c+=a[i--]-'0';
            if(j>=0) c+=b[j--]-'0';
            r+=c%2+'0';
            c/=2;
        }
        reverse(r.begin(),r.end());
        return r;

    }
};