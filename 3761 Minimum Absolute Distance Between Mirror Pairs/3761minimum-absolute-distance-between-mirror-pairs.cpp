class Solution {
    private:
    int reverse(int x){
        int r=0;
        while(x>0){
            r=r*10+x%10;
            x/=10;
        }
        return r;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){
                ans=min(ans,i-mp[nums[i]]);
            }
            mp[reverse(nums[i])]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};