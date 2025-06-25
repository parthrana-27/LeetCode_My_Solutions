class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        long long n=dividend,d=divisor,ans=0,shift=0;
        n=n<0?-n:n;
        d=d<0?-d:d;

        while(n>=d)
        {
           shift=0;
           while(n>=d<<(shift+1))
               shift++;
            ans+=1<<shift;
            n-=(d*1<<shift);  
        }

        return (dividend<0 ^ divisor<0)?-ans: ans;
    }
};