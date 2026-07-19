class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        stack<char>st;
        unordered_set<char>seen;
        for(char c:s){
            freq[c-'a']--;
            if(seen.count(c)) continue;
            while(!st.empty() && c<st.top() && freq[st.top()-'a']>0){
                seen.erase(st.top());
                st.pop();
            }
            st.push(c);
            seen.insert(c);
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};