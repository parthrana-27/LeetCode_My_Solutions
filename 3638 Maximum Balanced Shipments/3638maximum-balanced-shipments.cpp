class Solution {
public:

    int maxBalancedShipments(vector<int>& weight) {
        int count=0;
        int ma=weight[0];
        int n=weight.size();
        int start=0;
        for (int i=1;i<n; ++i) {
            ma= max(ma,weight[i]);
            if (weight[i] < ma) {
                count++;
                start = i + 1;
                i=start;
                if (i<n)
                    ma=weight[i];
            }
        }

        return count;
    }
};
