class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int len=2;len<=9;len++){
            for(int i=1;i+len<=10;i++){
                int val=0;
                for(int d=i;d<i+len;d++){
                    val=val*10+d;
                }
                if(val>=low && val<=high) ans.push_back(val);
            }
        }
        return ans;
    }
};