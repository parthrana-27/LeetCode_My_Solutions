class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        int m=grid.size();
        int n=grid[0].size();
        map<int,int>freq;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                freq[grid[i][j]]++;
            }
        }
        int fsum=0;
        for(auto &m:freq)
        {
            if(m.second==2)
            {
                ans.push_back(m.first);
            }
            fsum+=m.first;
        }
        int rsum=n*n*(n*n+1)/2;
        int diff=rsum-fsum;
        ans.push_back(diff);
        return ans;
    }
};