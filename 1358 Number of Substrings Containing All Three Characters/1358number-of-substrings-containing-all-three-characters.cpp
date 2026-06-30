class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>mp(3,-1);
        int c=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]-'a']=i;
            if(mp[0]!=-1 && mp[1]!=-1 && mp[2]!=-1){
                c+=1+min({mp[0],mp[1],mp[2]});
            }
        }
        return c;
    }
};