class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        int n=cost.size();
        int s=0;
        for(int i=0;i<n;i+=3){
            s+=cost[i];
            if(i+1<n) s+=cost[i+1];
        }
        return s;
    }
};