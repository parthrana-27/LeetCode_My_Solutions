class Solution {
public:
    int minFlips(string s){
        int n=s.length();
        int diff1=0;
        int diff2=0;
        int ans=INT_MAX;
        string s2=s+s;
        for(int i=0;i<2*n;i++){
            char p1=(i%2==0)?'0':'1';
            char p2=(i%2==0)?'1':'0';
            if(s2[i]!=p1) diff1++;
            if(s2[i]!=p2) diff2++;
            if(i>n-1){
                p1=((i-n)%2==0)?'0':'1';
                p2=((i-n)%2==0)?'1':'0';

                if(s2[i-n]!=p1) diff1--;
                if(s2[i-n]!=p2) diff2--;
            }
            if(i>=n-1){
                ans=min(ans,min(diff1,diff2));
            }
        } 
        return ans;
    }
};