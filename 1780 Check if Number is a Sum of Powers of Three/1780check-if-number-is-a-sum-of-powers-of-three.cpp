class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int>s;
        int p=1;
        while(p<=n)
        {
            s.push_back(p);
            p*=3;
        }
        for(int i=s.size()-1;i>=0;i--)
        {
            if(n>=s[i])
            {
                n-=s[i];
            }
        }
        return n==0;
    }
};