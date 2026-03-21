class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k){
        for(int i=0;i<k/2;i++){
            int tr=x+i;
            int br=x+k-1-i;
            for(int j=y;j<y+k;j++){
                swap(grid[tr][j],grid[br][j]);
            }
        }
        return grid;
    }
};