class Solution {
    private: 
    void f(int o,int c,int n,string curr,vector<string> &res){
        if(curr.size()==2*n){
            res.push_back(curr);
            return ;
        }
        if(o<n){
            f(o+1,c,n,curr+"(",res);
        }
        if(c<o) f(o,c+1,n,curr+")",res);
    }
public:
    vector<string> generateParenthesis(int n) {
       vector<string>res;
       f(0,0,n,"",res);
       return res;
    }
};