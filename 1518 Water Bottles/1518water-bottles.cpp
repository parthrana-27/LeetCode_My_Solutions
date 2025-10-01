class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int t=0;
        int e=0;
        while(numBottles>0)
        {
            t+=numBottles;
            e+=numBottles;
            numBottles=e/numExchange;
            e%=numExchange;
        }
        return t;
    }
};