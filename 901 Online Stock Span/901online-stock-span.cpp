class StockSpanner {
    private:
    stack<pair<int,int>>st;
    int ind=-1;
public:
    StockSpanner() { 
       ind=-1;
       stack<pair<int,int>>empty;
       st.swap(empty);
    }
    
    int next(int price) {
        int s=1;
        while(!st.empty() && st.top().first<=price){
            s+=st.top().second;
            st.pop();
        }
        st.push({price,s});
        return s;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */