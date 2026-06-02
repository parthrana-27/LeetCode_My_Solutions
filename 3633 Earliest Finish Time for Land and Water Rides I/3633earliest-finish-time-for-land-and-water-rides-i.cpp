class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int mi=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int fi_land=landStartTime[i]+landDuration[i];
                int st_water=max(fi_land,waterStartTime[j]);
                int fi_water=st_water+waterDuration[j];
                mi=min(mi,fi_water);

                int fi_water_f=waterStartTime[j]+waterDuration[j];
                int st_land=max(fi_water_f,landStartTime[i]);
                int fi_land_s=st_land+landDuration[i];
                mi=min(mi,fi_land_s);
            }
        }
        return mi;
    }
};