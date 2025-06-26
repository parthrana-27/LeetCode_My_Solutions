class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.length();
        int zero=0,one=0;
        long long val=0,pow=1;
        for(char c:s){
            if(c=='0') zero++;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1'){
                if(val+pow>k){
                    continue;
                }
                val+=pow;
                one++;
            }
            pow<<=1;
            if(pow>k) break;
        }
        return zero+one;
    }
};