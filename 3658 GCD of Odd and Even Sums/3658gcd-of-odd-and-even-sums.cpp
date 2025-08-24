class Solution {
public:
    int gcd(int sum1,int sum2)
    {
        int res=min(sum1,sum2);
        while(res > 0)
            {
                if(sum1%res==0 && sum2%res==0)
                {
                        break;
                }
                res--;
            }
        return res;
    }
    int gcdOfOddEvenSums(int n) {
        int sumodd=0;
        int sumeven=0;
        for(int i=0;i<n;i++)
            {
                sumeven+=2*(i+1);
                sumodd+=2*i+1;
            }
        return gcd(sumeven,sumodd);
    }
};