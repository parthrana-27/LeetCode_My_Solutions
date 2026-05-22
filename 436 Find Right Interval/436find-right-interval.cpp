class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& inter) {
        int n=inter.size();
        int m=inter[0].size();
        vector<int>ans(n);
        vector<pair<int,int>>sorted;
        for(int i=0;i<n;i++){
            sorted.push_back({inter[i][0],i});
        }
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<n;i++){
            int end=inter[i][1];
            auto it=lower_bound(sorted.begin(),sorted.end(),end,[](pair<int,int>& a,int val){
                    return a.first<val;
            });
            if(it !=sorted.end()){
                ans[i]=it->second;
            }else{
                ans[i]=-1;
            }
        }
        return ans;
    }
};