class Solution {
    private:
     int lcs(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int>prev(m+1,0),cur(m+1,0);
        for(int i=0;i<=m;i++) prev[i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) cur[j]=1+prev[j-1];
               else cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return prev[m];
    }
    int lcs(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
public:
    int minDistance(string word1, string word2) {
        return word1.size()+word2.size()-2*lcs(word1,word2);
    }
};