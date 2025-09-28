class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        long long mul=1;
        while(n>0)
            {
                long long val=n%10;
                if(val){
                ans.push_back((int)(val*mul));
                }
                mul*=10;
                n/=10;
            }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};