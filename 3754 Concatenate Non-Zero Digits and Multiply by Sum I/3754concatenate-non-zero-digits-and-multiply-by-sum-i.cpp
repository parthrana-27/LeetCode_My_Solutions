class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        long long sum=0;
        string s=to_string(n);
        for(char c:s){
            int v=c-'0';
            if(v!=0){
                x=x*10+v;
                sum+=v;
            }
        }
        return x*sum;
    }
};