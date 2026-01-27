class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        if(n==1) return 1;
        int i=n-1;
        int len=0;
        while(s[i]==' ' && i>=0){
           i--;
        }
        while(i>=0 && s[i]!=' '){
            len++;
            i--;
        }
        return len;
    }
};