class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int ans=0;
        stack<char>st;
        for(char c:s){
            if(c=='a' && !st.empty() && st.top()=='b'){
                st.pop();
                ans++;
            }else{
                st.push(c);
            }
        }
        return ans;
    }   
};