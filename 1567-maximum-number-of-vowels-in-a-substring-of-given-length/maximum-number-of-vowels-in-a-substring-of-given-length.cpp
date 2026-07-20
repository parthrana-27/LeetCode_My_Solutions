class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int cur=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' ||
               s[i]=='o' || s[i]=='u' ||
               s[i]=='i'){
                cur++;
            }
        }
        int ma=cur;
        for(int i=k;i<n;i++){
            if(s[i-k]=='a' || s[i-k]=='e' ||
               s[i-k]=='o' || s[i-k]=='u' ||
               s[i-k]=='i'){
                cur--;
               }
            if(s[i]=='a' || s[i]=='e' ||
               s[i]=='o' || s[i]=='u' ||
               s[i]=='i'){
                cur++;
               }
            ma=max(ma,cur);
        }
        return ma;
    }
};