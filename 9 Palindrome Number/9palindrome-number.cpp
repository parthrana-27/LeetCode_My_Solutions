class Solution {
public:
    bool isPalindrome(int x) {
        if(x >= 0)
        {
            long sum=0;
            long m=x;
            while(x>0)
            {
                long n=x % 10;
                sum=sum*10+n;
                x=x/10;
               
            }
             if(sum==m)
                {
                    return true;
                }
                else
                {
                    return false;
                }
        }
        else{
            return false;
        }
        return 0;
    }
};