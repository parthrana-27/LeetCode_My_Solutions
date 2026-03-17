class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>h(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    h[j]=0;
                }else{
                    h[j]++;
                }
            }
        
        vector<int>q=h;
        sort(q.begin(),q.end());
        for(int i=0;i<m;i++){
            ans=max(ans,(q[i])*(m-i));
        }
        }
        return ans;
    }
};