class Solution {
    private:
    int maxel(vector<vector<int>>& mat,int n,int m,int mid){
        int ma=INT_MIN;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>ma){
                ma=mat[i][mid];
                ind=i;
            }
        }
        return ind;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0,h=m-1;
        while(l<=h){
            int mid=(l+h)>>1;
            int row=maxel(mat,n,m,mid);
            int left=mid-1>=0 ? mat[row][mid-1]:-1;
            int right=mid+1<m ? mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right) return {row,mid};
            else if(mat[row][mid]<left) h=mid-1;
            else l=mid+1;
        }
        return {-1,-1};
        }
};