class Solution {
private:
    int MOD=1e9+7;
    typedef long long ll;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.length();
        vector<int>nonZ;
        vector<int>pos;
        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                nonZ.push_back(s[i]-'0');
                pos.push_back(i);
            }
        }
        int m=nonZ.size();
        if(m==0){
            vector<int>ans(queries.size(),0);
            return ans;
        }
        vector<ll>prefS(m+1,0);
        vector<ll>prefV(m+1,0);
        vector<ll>pow10(m+1,1);
        for(int i=0;i<m;i++){
            prefS[i+1]=(prefS[i]+nonZ[i])%MOD;
            prefV[i+1]=(prefV[i]*10+nonZ[i])%MOD;
            pow10[i+1]=(pow10[i]*10)%MOD;
        }
        vector<int>ans;
        for(auto& q:queries){
            int l=q[0];
            int r=q[1];
            auto s=lower_bound(pos.begin(),pos.end(),l);
            auto e=upper_bound(pos.begin(),pos.end(),r);
            int idxs=distance(pos.begin(),s);
            int idxe=distance(pos.begin(),e);
            if(idxs==m || pos[idxs]>r){
                ans.push_back(0);
                continue;
            }
            int c=idxe-idxs;
            long long x=(prefV[idxe]-(prefV[idxs]*pow10[c])%MOD+MOD)%MOD;
            long long sum=(prefS[idxe]-prefS[idxs]+MOD)%MOD;
            long long res=(x*sum)%MOD;
            ans.push_back((int)res);
        }
        return ans;
    }
};