class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            vector<int>freq(26,0);
            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;

                int ma=0;
                int mi=INT_MAX;
                for(int k=0;k<26;k++)
                {
                    if(freq[k]>0)
                    {
                        mi=min(mi,freq[k]);
                        ma=max(ma,freq[k]);
                    }
                }
                ans+=(ma-mi);
            }

        }
        return ans;
    }
};