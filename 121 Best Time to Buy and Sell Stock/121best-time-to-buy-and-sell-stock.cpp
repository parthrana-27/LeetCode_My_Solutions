class Solution {
public:

    int maxProfit(vector<int>& prices) {
       int mi=INT_MAX;
       int ma=0;
       for(int p:prices){
        mi=min(mi,p);
        ma=max(ma,p-mi);
       }
       return ma;
    }
};