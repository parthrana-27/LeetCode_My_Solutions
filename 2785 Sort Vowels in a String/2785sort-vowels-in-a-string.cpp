class Solution {
public:
    string sortVowels(string s) {
        int n=s.length();
        vector<char>vowels;
        for(char c:s){
            if(isv(c)){
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(),vowels.end());
        int v_in=0;
        for(int i=0;i<s.size();i++)
        {
            if(isv(s[i])){
                s[i]=vowels[v_in++];
            }
        }
        return s;
    }
    bool isv(char c){
        return string("AEIOUaeiou").find(c)!=string::npos;
    }
};