class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=1;i<n;i++){
            string next="";
            for(int j=0;j<ans.length();j++){
                int c=1;
                while(j+1<ans.length() && ans[j]==ans[j+1]){
                    c++;
                    j++;
                }
                next+=to_string(c)+ans[j];
            }
            ans=next;
        }
        return ans;
    }
};