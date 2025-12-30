class Solution {
private: 
bool ismagic(vector<vector<int>>& g,int r,int c){
    int sum=0;
    int first=true;
    vector<bool>seen(10,false);
    if (g[r+1][c+1]!=5) return false;
    for(int i=0;i<3;i++){
        int cur1=0,cur2=0;
        for(int j=0;j<3;j++){
            int val=g[r+i][c+j];
            if(val<1||val>9||seen[val])
                return false;
            seen[val]=true;
            cur1+=g[r+i][c+j];
            cur2+=g[r+j][c+i];
        }
        if(cur1 != cur2) return false;
        if(first){ first=false;
        sum=cur1;
        }
        else{
            if(cur1 != sum || cur2 != sum) return false;
        }
    }
    int diag1=g[r][c]+g[r+1][c+1]+g[r+2][c+2];
    int diag2=g[r][c+2]+g[r+1][c+1]+g[r+2][c];
    if(diag1 != diag2) return false;
    if(diag1 != sum || diag2 != sum) return false;
    return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n<3 || m<3) return 0;
        int ans=0;
        for(int i=0;i+2<n;i++){
            for(int j=0;j+2<m;j++){
                if(ismagic(grid,i,j)) ans++;
            }
        }
        return ans;
    }
};