class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        long long sum=0;
        long long nc=0;
        long long mn=LLONG_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] < 0){
                    nc++;
                }
                    sum+=llabs(matrix[i][j]);
                    mn=min(mn,llabs(matrix[i][j]));
            }  
        }
        if(nc%2 ==1){
            sum-=2*mn;
        }
        return sum;
    }
};