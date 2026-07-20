class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<string,int>rc;
        for(int i=0;i<n;i++){
            string r="";
            for(int j=0;j<n;j++){
                r+=to_string(grid[i][j])+"_";
            }
            rc[r]++;
        }
        int cnt=0;
        for(int j=0;j<n;j++){
            string c="";
            for(int i=0;i<n;i++){
                c+=to_string(grid[i][j])+"_";
            }
            if(rc.count(c)){
                cnt+=rc[c];
            }
        }
        return cnt;
    }
};