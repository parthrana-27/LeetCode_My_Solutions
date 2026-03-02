class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>last(n,-1);
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1){
                    last[i]=j;
                    break;
                }
            }
        }
        int s=0;
        for(int i=0;i<n;i++){
            int t=i;
            while(t<n &&last[t]>i) t++;
            if(t==n) return -1;
            while(t>i){
                swap(last[t],last[t-1]);
                t--;
                s++;
            }
        }
        return s;
    }
};