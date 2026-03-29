class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int k=1;k<=n;k++){
            if(n%k!=0) continue;
            if(k==1){
                if(is_sorted(nums.begin(),nums.end())) ans+=1;
                continue;
            }
            bool ok=true;
            vector<int>a,b;
            for(int s=0;s<n;s+=k){
                int cnt=0;
                for(int i=0;i<k;i++){
                    int cur=nums[s+i];
                    int next=nums[s+(i+1)%k];
                    if(cur>next) cnt++;
                }
                if(cnt>1){
                    ok=false;
                    break;
                }
                int mi=*min_element(nums.begin()+s,nums.begin()+s+k);
                int ma=*max_element(nums.begin()+s,nums.begin()+s+k);
                a.push_back(mi);
                b.push_back(ma);
                }
                for(int i=0;i+1<a.size();i++){
                    if(b[i]>a[i+1]){
                        ok=false;
                        break;
                    }
                }
            if(ok) ans+=k;
            }
        return ans;
    }
};