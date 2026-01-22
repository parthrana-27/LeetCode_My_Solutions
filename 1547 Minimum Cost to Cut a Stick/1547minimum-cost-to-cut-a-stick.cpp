class Solution {
public:
    int minCost(int n, vector<int>& cuts){
        int c=cuts.size();
        cuts.push_back(n);
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        cuts.insert(cuts.begin(),0); 
        sort(cuts.begin(),cuts.end());
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                 if(i>j) continue;
                 int mi=INT_MAX;
                 for(int ind=i;ind<=j;ind++){
                 int c=cuts[j+1]-cuts[i-1]+dp[ind+1][j]+dp[i][ind-1];
                 mi=min(mi,c);
                }
                dp[i][j]=mi;
            }
        }
        return dp[1][c];
    }
};