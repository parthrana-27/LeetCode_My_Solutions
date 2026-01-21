class Solution {

public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int>after(2*k+1,0);
        vector<int>cur(2*k+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=2*k-1;j>=0;j--){
                    if(j%2==0)
                    cur[j]=max(-prices[i]+after[j+1],after[j]);
                    else
                    cur[j]=max(prices[i]+after[j+1],after[j]);
                }
            after=cur;
        }
        return after[0];
    }
};