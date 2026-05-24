class Solution {
    private: 
    int dfs(int i,int n,int d,vector<int>& arr,vector<int>& dp){
        if(dp[i]!=-1) return dp[i];
        int ma=1;
        for(int x=1;x<=d;x++){
            int r=i+x;
            if(r>=n) break;
            if(arr[r]>=arr[i]) break;
            ma=max(ma,1+dfs(r,n,d,arr,dp));
        }
        for(int x=1;x<=d;x++){
            int l=i-x;
            if(l<0) break;
            if(arr[l]>=arr[i]) break;
            ma=max(ma,1+dfs(l,n,d,arr,dp));
        }
        return dp[i]=ma;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int>dp(n,-1);
        int res=0;
        for(int i=0;i<n;i++){
            res=max(res,dfs(i,n,d,arr,dp));
        }
        return res;
    }
};