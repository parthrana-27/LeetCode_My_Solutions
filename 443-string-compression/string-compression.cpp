class Solution {
public:
    int compress(vector<char>& chars) {
        int l=0,r=0;
        int n=chars.size();
        while(r<n){
            char c=chars[r];
            int cnt=0;
            while(r<n && chars[r]==c){
                r++;
                cnt++;
            }
            chars[l++]=c;
            if(cnt>1){
                string cs=to_string(cnt);
            for(char d:cs){
                chars[l++]=d;
                }
            }
        }
        return l;
    }
};