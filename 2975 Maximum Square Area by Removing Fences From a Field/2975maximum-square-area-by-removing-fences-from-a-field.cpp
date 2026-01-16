class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod=1e9+7;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        unordered_set<int>hgap,vgap;
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                hgap.insert(hFences[j]-hFences[i]);
            }
        }
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                vgap.insert(vFences[j]-vFences[i]);
            }
        }
        long long best=-1;
        for(int g:hgap){
            if(vgap.count(g)){
                best=max(best,(long long)g);
            }
        }
        return best==-1?-1:(best*best)%mod;
    }
};