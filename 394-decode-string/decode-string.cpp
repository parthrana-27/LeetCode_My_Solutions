class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        stack<int>cnt;
        string cur="";
        int k=0;
        for(char c:s){
            if(isdigit(c)){
                k=k*10+(c-'0');
            }else if(c=='['){
                cnt.push(k);
                st.push(cur);
                k=0;
                cur="";
            }else if(c==']'){
                int rep=cnt.top();
                cnt.pop();
                string prev=st.top();
                st.pop();
                for(int i=0;i<rep;i++){
                    prev+=cur;
                }
                cur=prev;
            }else{
                cur+=c;
            }
        }
        return cur;
    }
};