class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mp;
        for(char ch:word)
        {
            mp[ch]++;
        }
        vector<int>freq;
        for(auto&[ch,c]:mp)
        {
            freq.push_back(c);
        }
        sort(freq.begin(),freq.end());
        int n=freq.size();
        int mi=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int base=freq[i];
            int del=0;
            for(int j=0;j<i;j++)
            {
                del+=freq[j];
            }
            for(int j=i+1;j<n;j++)
            {
                 if(freq[j]>base+k)
                {
                    del+=freq[j]-(base+k);
                }
            }
            mi=min(mi,del);
        }
        return mi;
    }
};