class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0,h=n*m-1;
        while(l<=h){
            int mid=(l+h)>>1;
            int row=mid/m;
            int col=mid%m;
            if(mat[row][col]==target){
                return true;
            }else if(mat[row][col]>target){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
};