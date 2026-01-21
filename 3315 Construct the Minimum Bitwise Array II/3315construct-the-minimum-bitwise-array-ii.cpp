class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(x==2){
                v[i]=-1;
                continue;
            }
            int temp=x;
            int cnt=0;
            while((temp&1)==1){
                cnt++;
                temp >>=1;
                }
                v[i]=x-(1<<(cnt-1));
            }         
        return v;
    }
};