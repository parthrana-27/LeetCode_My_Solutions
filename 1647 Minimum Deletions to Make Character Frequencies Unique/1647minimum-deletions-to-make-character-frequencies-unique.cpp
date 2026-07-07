class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        unordered_set<int>seen;
        int ans=0;
        for(int f:freq){
            while(f>0 &&  seen.count(f)){
                f--;
                ans++;
            }
            if(f>0) seen.insert(f);
        }
        return ans;
    }
};