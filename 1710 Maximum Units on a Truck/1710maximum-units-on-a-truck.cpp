class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](auto& a,auto& b){
            return a[1]>b[1];
        });
        int total=0;
        for(auto& box:boxTypes){
            int c=min(truckSize,box[0]);
            total+=c*box[1];
            truckSize-=c;
            if(truckSize==0) break;
        }
        return total;
    }
};