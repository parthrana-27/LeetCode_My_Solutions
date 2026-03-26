class Solution {
    private:
    vector<int>f,l;
    int getend(int st,string s){
        int e=l[s[st]-'a'];
        for(int j=st;j<=e;j++){
            int c=s[j]-'a';
            if(f[c]<st) return -1;
            e=max(e,l[c]);
        }
        return e;
    }
    vector<string> greedy(string s,int n){
        vector<string>res;
        int prev=-1;
        for(int i=0;i<n;i++){
            if(i==f[s[i]-'a']){
                int e=getend(i,s);
                if(e==-1) continue;
                if(i>prev){
                    res.push_back(s.substr(i,e-i+1));
                    prev=e;
                }else{
                    if(e<prev){
                        res.back()=s.substr(i,e-i+1);
                        prev=e;
                    }
                }
            }
        }
        return res;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        f.assign(26,INT_MAX);
        l.assign(26,INT_MIN);
        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            f[c]=min(f[c],i);
            l[c]=max(l[c],i);
        }
        return greedy(s,n);
    }
};