class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
       vector<long long>a(n,INT_MAX);
        a[0]=0;
        for(auto it:restrictions){
            int idx=it[0];
            int ma=it[1];
            a[idx]=min(a[idx],(long long)ma);
        }
        for(int i=1;i<n;i++){
            a[i]=min(a[i],a[i-1]+diff[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            a[i]=min(a[i],a[i+1]+diff[i]);
        }
        return (int)*max_element(a.begin(),a.end());
    }
};
