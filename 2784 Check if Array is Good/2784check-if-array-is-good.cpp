class Solution {
public:
    bool isGood(vector<int>& nums) {
        int ma=0;
        for(int v:nums) ma=max(v,ma);
        int n=ma;
        if(nums.size() !=n+1) return false;
        vector<int>freq(n+1,0);
        for(int v:nums) freq[v]++;
        for(int i=1;i<n;i++){
            if(freq[i]!=1) return false;
        }
        if(freq[n]!=2) return false;
        return true;
    }
};