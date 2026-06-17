class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.length();
        vector<long long>len(n);
        long long cur=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c>='a' && c<='z'){
                cur++;
            }else if(c=='*'){
                if(cur>0) cur--;
            }else if(c=='#'){
                cur*=2;
            }
            len[i]=cur;
        }
        if(k>=cur) return '.';
        for(int i=n-1;i>=0;i--){
            char c=s[i];
            long long prev=0;
            if(c>='a' && c<='z'){
                if(k==len[i]-1){
                    return c;
                }
                prev=len[i]-1;
            }
            else if(c=='*'){
                prev=len[i]+1;
            }
            else if(c=='#'){
                prev=len[i]/2;
                if(k>=prev){
                    k-=prev;
                }
            }
            else if(c=='%'){
                prev=len[i];
                k=prev-1-k;
            }
        }
        return '.';
    }
};