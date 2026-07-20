class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int n=arr.size();
        vector<int>pref(n+1,0);
        vector<int>suff(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i]=arr[i-1]+pref[i-1];
        }
        for(int i=n-1;i>=0;i--){
            suff[i]=arr[i]+suff[i+1];
        }
        for(int i=0;i<n;i++){
            if(pref[i]==suff[i+1]) return i;
        }
        return -1;
    }
};