class Solution {
public:
    long long coloredCells(int n) {
        if(n==1) return 1;
        long long sum=1;
        for(long long i=2;i<=n;i++)
        {
            sum+=4*(i-1);
        }
        return sum;
    }
};