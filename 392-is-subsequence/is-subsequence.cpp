class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        int i=0,j=0;
        while(i<n && j<m){
            char cur=s[i];
            if(cur!= t[j]){
                j++;
            }else{
                i++;
                j++;
            }
            cout << cur;
        }
        return i==n;
    }
};