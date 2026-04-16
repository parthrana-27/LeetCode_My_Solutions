class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        vector<int>ans;
        for(int idx:queries){
            int val=nums[idx];
            if(mp[val].size()==1){
                ans.push_back(-1);
                continue;
            }
            auto &v=mp[val];
            auto it=lower_bound(v.begin(),v.end(),idx);
            int pos=it-v.begin();
            int best=INT_MAX;
            int next=v[(pos+1)%v.size()];
            int d1=abs(next-idx);
            d1=min(d1,n-d1);
            int prev=v[(pos-1+v.size())%v.size()];
            int d2=abs(idx-prev);
            d2=min(d2,n-d2);
            best=min(d1,d2);
            ans.push_back(best);
        }
        return ans;
    }
};