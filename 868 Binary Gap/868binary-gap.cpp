class Solution {
public:
    int binaryGap(int n){
        int l=-1;
        int p=0;
        int ans=0;
        while(n>0){
            if(n&1){
                if(l!=-1){
                    ans=max(ans,p-l);
                }
                l=p;
            }
            n>>=1;
            p++;
        }
        return ans;
    }
};