class Solution {
public:
    string removeDuplicateLetters(string s) {
        int l=s.length();
        unordered_set<char>cs;
        stack<char>st;
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        for(char c:s){
            freq[c-'a']--;
            if(cs.count(c)) continue;
            while(!st.empty() && st.top()>c && freq[st.top()-'a']>0){
                cs.erase(st.top());
                st.pop();
            }
            st.push(c);
            cs.insert(c);
        }
        string res="";
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};