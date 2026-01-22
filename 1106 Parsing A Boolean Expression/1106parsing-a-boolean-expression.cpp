class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(char c:expression){
            if(c==','||c==' ') continue;
            if(c==')'){
                vector<char>vals;
                while(!st.empty() && st.top()!='('){
                    vals.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                char res;
                if(op=='!'){
                    res=(vals[0]=='t')?'f':'t';
                }else if(op=='&'){
                    res='t';
                    for(char v:vals) if(v=='f'){
                        res='f';
                        break;
                    }
                }else if(op=='|'){
                    res='f';
                    for(char v:vals) if(v=='t'){
                        res='t';
                        break;
                    }
                }
                st.push(res);
            }else{
                st.push(c);
            }
        }
        return st.top()=='t';
    }
};