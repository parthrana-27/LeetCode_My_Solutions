class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        vector<int>dev(n,0);
        for(int i=0;i<n;i++){
            for(char c:bank[i]){
                if(c=='1'){
                    dev[i]++;
                }
            }
        }
        int ans=0,prev=0;
        for(int i=0;i<n;i++){
            if(dev[i]==0) continue;
            ans+=prev*dev[i];
            prev=dev[i];
        }
        return ans;
    }
};