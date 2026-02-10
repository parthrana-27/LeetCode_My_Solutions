class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int>mp;
        for(char c:t) mp[c]++;
        int l=0,r=0;
        int mi=INT_MAX;
        int cnt=0;
        int s_ind=-1;
        while(r<n){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;
            while(cnt==m){
                if(r-l+1<mi){
                    mi=r-l+1;
                    s_ind=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return s_ind == -1 ? "" :s.substr(s_ind,mi); 
    }
};