class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size();
        int m=boxGrid[0].size();
        for(int i=0;i<n;i++){
            int writ=m-1;
            for(int j=m-1;j>=0;j--){
                char cell=boxGrid[i][j];
                if(cell=='*'){
                    writ=j-1;
                }else if(cell=='#'){
                    if(j!=writ){
                        boxGrid[i][writ]='#';
                        boxGrid[i][j]='.';
                    }
                    writ--;
                }
            }
        }
        vector<vector<char>>ans(m,vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][n-1-i]=boxGrid[i][j];
            }
        }
        return ans;
    }
};