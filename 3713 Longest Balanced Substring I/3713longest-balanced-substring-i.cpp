class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int mi=INT_MAX,ma=INT_MIN;
                for(int f:freq){
                    if(f>0){
                        mi=min(mi,f);
                        ma=max(ma,f);
                    }
                }
                if(mi==ma){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};