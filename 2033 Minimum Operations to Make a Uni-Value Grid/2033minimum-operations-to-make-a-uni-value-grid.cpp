class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>a;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                a.push_back(grid[i][j]);
            }
        }
        sort(a.begin(),a.end());
        int r=a[0]%x;
        for(int num:a)
        {
            if(num % x != r)
            return -1;
        }
        
        int mid=a[a.size()/2];
        int c=0;
        for(int num : a)
        {
            c+=abs(num-mid)/x;
        }
        return c;
    }
};