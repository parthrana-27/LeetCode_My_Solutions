class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length();
        int t=1<<k;
        if(n<k || n<t) return false;
        unordered_set<string>code;
        for(int i=0;i<n-k+1;i++){
            code.insert(s.substr(i,k));
        }
        if(code.size()==t) return true;
        return false;
    }
};