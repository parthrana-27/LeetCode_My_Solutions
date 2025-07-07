class MinStack {
    private:
    stack<long>st;
    long mi=INT_MAX;
public:
    MinStack() {     
    }
    
    void push(int val) {
        if(st.empty()){
            mi=val;
            st.push((long)val);
        }
        else{
            if(val>mi) st.push((long)val);
            else {st.push(2*(long)val-mi);
            mi=val;}
        }
    }
    
    void pop() {
        if(st.empty()) return ;
        long x=st.top();
        st.pop();
        if(x<mi)
        mi=2*mi-x;
    }
    
    int top() {
        if(st.empty()) return -1;
        long x=st.top();
        if(mi<x) return x;
        return mi;
    }
    
    int getMin() {
        return (int)mi;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */