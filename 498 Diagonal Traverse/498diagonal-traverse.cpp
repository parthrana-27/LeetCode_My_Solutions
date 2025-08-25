class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<int>ans;
        int row=n+m-1;
        int i=0,j=0;
        bool u=true;
        while(ans.size()<m*n)
        {
            ans.push_back(mat[i][j]);
            if(u)
            {
                if(j==m-1)
                {
                    i++;
                    u=false;
                }else if(i==0)
                {
                    j++;
                    u=false;
                }else{
                    i--;
                    j++;
                }
            }else{
                if(i==n-1)
                {
                    j++;
                    u=true;
                }else if(j==0)
                {
                    i++;
                    u=true;
                }else{
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};