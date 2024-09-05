class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int total_sum=mean*(n+m);
        int k_sum=accumulate(rolls.begin(),rolls.end(),0);
        int missing_sum=total_sum-k_sum;
        int remainder=missing_sum%n;
         std::vector<int> result(n, missing_sum / n);
        if(missing_sum<n||missing_sum>6*n)
        {
            return{};
        }
       for(int i=0;i<remainder;i++)
        {
            result[i]++;
        }
        return result;
    }
};