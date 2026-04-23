class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        vector<long long>arr(n,0);
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto& [v,ind]:mp){
            int m=ind.size();
            if(m==1) continue;
            vector<long long>pref(m+1,0);
            for(int k=0;k<m;k++){
                pref[k+1]=pref[k]+ind[k];
            }
            for(int k=0;k<m;k++){
                long long i=ind[k];
                long long l=i*k-pref[k];
                long long rc=m-k-1;
                long long r=(pref[m]-pref[k+1])-i*rc;
                arr[i]=l+r;
            }
        }
        return arr;
    }
};