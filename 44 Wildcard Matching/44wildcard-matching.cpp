class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<bool>prev(m+1,0),cur(m+1,0);
        prev[0]=true;
        for(int j=1;j<=m;j++){
            int flag=true;
            for(int jj=1;jj<=j;jj++){
                if(p[jj-1]!='*'){
                    flag=false;
                    break;
                }
            }
            prev[j]=flag;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(s[i-1]==p[j-1] || p[j-1]=='?')  cur[j]=prev[j-1];
                    else if(p[j-1]=='*'){
                        cur[j]=prev[j] | cur[j-1];
                    }
                    else cur[j]=false;
            }
            prev=cur;
        }
        return prev[m];
    }
};