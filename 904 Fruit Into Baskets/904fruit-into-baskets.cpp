class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int s=0 ,ma=0;
        unordered_map<int,int>basket;

        for (int i=0;i<fruits.size();i++)
         {
            basket[fruits[i]]++;
            while(basket.size()>2) {
                basket[fruits[s]]--;
                if (basket[fruits[s]]==0) {
                    basket.erase(fruits[s]);
                }
                s++;
            }
            ma=max(ma,i-s+1);
        }

        return ma;
    }
};