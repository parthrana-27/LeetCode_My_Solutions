class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=INT_MIN;
        int ind=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) cnt++;
            }
            if(ans<cnt){
                ans=cnt;
                ind=i;
            }
        }
        return {ind,ans};
    }
};