class Solution {
    private:
    bool ispal(string &s,int i,int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
    void f(int i,string &s,vector<string>path,vector<vector<string>>&res){
        if(i==s.length()){
            res.push_back(path);
            return;
        }
        for(int ind=i;ind<s.length();ind++){
            if(ispal(s,i,ind)){
                path.push_back(s.substr(i,ind-i+1));
                f(ind+1,s,path,res);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        f(0,s,path,res);
        return res;
    }
};