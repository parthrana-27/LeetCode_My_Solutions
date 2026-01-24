class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>&arr){
        int n=arr.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        int ma=1;
        int last=0;
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>ma){
                ma=dp[i];
                last=i;
            }
        }
        vector<int>lis;
        lis.push_back(arr[last]);
        while(hash[last]!=last){
            last=hash[last];
            lis.push_back(arr[last]);
        }
        reverse(lis.begin(),lis.end());
        return lis;
    }
};