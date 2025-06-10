class Solution {
public:
    int maxDifference(string s) {
        map<char,int>freq;
        for(char ch:s){
            freq[ch]++;
        }
        int maxi=0,mini=s.size();
        for(auto str:freq){
            if(str.second % 2 != 0) maxi=max(maxi,str.second);
            if(str.second % 2 == 0 && str.second > 0) mini =min(mini,str.second);
        }
        return maxi - mini;
        
    }
};