class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int a_not_buy,a_buy,cur_buy,cur_not_buy;
        a_not_buy=a_buy=0;
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            // sell
            cur_not_buy=max(prices[i]-fee+a_buy,0+a_not_buy);
            // buy
            cur_buy=max(-prices[i]+a_not_buy,a_buy);
            a_buy=cur_buy;
            a_not_buy=cur_not_buy;
        }
        return a_buy;
    }
};