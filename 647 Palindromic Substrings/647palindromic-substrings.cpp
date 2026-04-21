class Solution {
    private:
    int f(string &s,int l,int r){
        int c=0;
        while(l>=0 && r< s.length() && s[l]==s[r]){
            c++;
            l--;
            r++;
        }
        return c;
    }
public:
    int countSubstrings(string s) {
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++){
            c+=f(s,i,i);
            c+=f(s,i,i+1);
        }
        return c;
    }
};