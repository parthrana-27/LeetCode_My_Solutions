class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();
        int m=INT_MAX;
        for(int i=0;i<=n-k;i++)
        {
            int c=0;
            for(int j=i;j<i+k;j++)
            {
                if(blocks[j]=='W')
                {
                    c++;
                }
            }
            m=min(m,c);
        }
        return m;
    }
};