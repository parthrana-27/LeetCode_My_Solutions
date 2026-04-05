class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        if(n==0) return s;
        long long base=31;
        long long mod=1e9+7;
        long long f=0,r=0,p=1;
        int idx=-1;
        for(int i=0;i<n;i++){
            int val=s[i]-'a'+1;
            f=(f*base+val)%mod;
            r=(r+val*p)%mod;
            if(f==r)
            idx=i;
            p=(p*base)%mod;
        }
        string suf=s.substr(idx+1);
        reverse(suf.begin(),suf.end());
        return suf+s;
    }
};