class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string>spe;
        int n=s.size();
        int i=0;
        int c=0;
        for(int j=0;j<n;j++){
        c+=(s[j]=='1'?1:-1);
        if(c==0){
            string inner=s.substr(i+1,j-i-1);
            spe.push_back("1"+makeLargestSpecial(inner)+"0");
            i=j+1;
            }
        }
        sort(spe.rbegin(),spe.rend());
        string ans="";
        for(const string& s:spe){
            ans+=s;
        }
        return ans;
    }
};