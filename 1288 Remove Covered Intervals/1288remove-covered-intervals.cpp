class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int c=0;
        int cur_ma=0;
        for(auto& inter:intervals){
            if(inter[1]>cur_ma){
                cur_ma=inter[1];
                c++;
            }
        }
        return c;
    }
};