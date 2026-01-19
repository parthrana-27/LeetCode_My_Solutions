class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ps(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                ps[i][j]=mat[i-1][j-1]+ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1];
            }
        }
        auto can=[&](int k){
            for(int i=0;i+k<=m;i++){
                for(int j=0;j+k<=n;j++){
                    int sum=ps[i+k][j+k]-ps[i][j+k]-ps[i+k][j]+ps[i][j];
                    if(sum<=threshold) return true;
                }
            }
            return false;
        };
        int l=1,h=min(m,n),ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(can(mid)){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};