class Solution {
public:
    int countBinarySubstrings(string s) {
        int p=0;
        int n=s.size();
        int c=1;
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                c++;
            }
            else{
                ans+=min(c,p);
                p=c;
                c=1;
            }
        }
        return ans+min(c,p);
    }
};