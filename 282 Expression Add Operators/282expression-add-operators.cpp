class Solution {
    void dfs(string &s,long t,int ind,vector<string>&res,string exp,long cur,long last){
        if(ind == s.size()){
            if(cur==t) res.push_back(exp);
        }
        for(int i=ind;i<s.size();i++){
            if(i>ind && s[ind]=='0') break;

            string part=s.substr(ind,i-ind+1);
            long val=stol(part);
            if(ind==0){
                dfs(s,t,i+1,res,part,cur+val,val);
            }
            else{
                dfs(s,t,i+1,res,exp+'*'+part,cur-last+last*val,last*val);
                dfs(s,t,i+1,res,exp+'-'+part,cur-val,-val);
                dfs(s,t,i+1,res,exp+'+'+part,cur+val,val);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        dfs(num,target,0,ans,"",0,0);
        return ans;
    }
};