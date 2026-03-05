class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int ans_0=0;
        int ans_1=0;
        for(int i=0;i<n;i++){
            char s_0=(i%2==0)?'0':'1';
            char s_1=(i%2==0)?'1':'0';
            
            if(s[i]!=s_0) ans_0++;
            if(s[i]!=s_1) ans_1++;
        }
        return min(ans_0,ans_1);    
    }
};