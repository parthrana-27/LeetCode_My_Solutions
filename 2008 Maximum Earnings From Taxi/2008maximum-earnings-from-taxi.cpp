class Solution {
public:
    long long dp[100005];
    long long solve(int idx,vector<vector<int>>& rides, vector<int>& st){
        if (idx>=rides.size())
            return 0;
        if (dp[idx]!=-1)
            return dp[idx];
        long long skip=solve(idx+1,rides,st);
        long long take=(rides[idx][1]-rides[idx][0])+rides[idx][2];
        int next=lower_bound(st.begin(),st.end(),rides[idx][1]) -
                   st.begin();
        take+=solve(next,rides,st);
        return dp[idx]=max(skip,take);
    }
    long long maxTaxiEarnings(int n,vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        vector<int>st;
        for (auto& r:rides)
            st.push_back(r[0]);
        memset(dp,-1,sizeof(dp));
        return solve(0, rides,st);
    }
};