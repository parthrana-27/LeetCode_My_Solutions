class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return {};
        vector<pair<int,int>>idx(n);
        for(int i=0;i<n;i++) idx[i]={arr[i],i};
        sort(idx.begin(),idx.end(),[] (pair<int,int>& a,pair<int,int>& b){
            return a.first<b.first;
        });
        vector<int>ans(n);
        int r=1;
        for(int i=0;i<n;i++){
            if(i==0 || idx[i].first != idx[i-1].first){
                r=(i==0) ? 1:r+1; 
            }
            ans[idx[i].second]=r;
        }
        return ans;
    }
};