class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        vector<int>odds1(26,0),odds2(26,0);
        vector<int>evens1(26,0),evens2(26,0);
        for(int i=0;i<n;i++){
            if(i%2==0){
                evens1[s1[i]-'a']++;
                evens2[s2[i]-'a']++;
            }else{
                odds1[s1[i]-'a']++;
                odds2[s2[i]-'a']++;
            }
        }
        return odds1==odds2 && evens1==evens2;
    }
};