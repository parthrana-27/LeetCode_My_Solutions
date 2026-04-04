class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string rep=a;
        int c=1;
        int n=a.length();
        int m=b.length();
        while(rep.length()<m){
            rep+=a;
            c++;
        }
        if(rep.find(b)!=string::npos) return c;
        rep+=a;
        c++;
        if(rep.find(b)!=string::npos) return c;
        return -1;
    }
};