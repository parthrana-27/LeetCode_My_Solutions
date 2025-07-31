class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
    vector<pair<int,int>>soldiers;
        for(int i=0;i<m;i++)
        {
            int cur=0;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1) cur++;
            }
            soldiers.push_back({cur,i});
        }
        vector<int>res;
        sort(soldiers.begin(),soldiers.end());
        for(int i=0;i<k;i++)
        {
            res.push_back(soldiers[i].second);
        }
        return res;
    }

};