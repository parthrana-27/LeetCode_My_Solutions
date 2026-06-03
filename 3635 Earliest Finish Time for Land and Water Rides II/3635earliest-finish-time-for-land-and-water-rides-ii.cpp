class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int mi_land=1e6,mi_water=1e6;
        for(int i=0;i<n;i++){
            mi_land=min(mi_land,landStartTime[i]+landDuration[i]);
        }
        for(int j=0;j<m;j++){
            mi_water=min(mi_water,waterStartTime[j]+waterDuration[j]);
        }
        int ans=1e9;
        for(int j=0;j<m;j++){
            if(waterStartTime[j]<mi_land){
                ans=min(ans,mi_land+waterDuration[j]);
            }else{
                ans=min(ans,waterStartTime[j]+waterDuration[j]);
            }
        }
        for(int i=0;i<n;i++){
            if(landStartTime[i]<mi_water){
                ans=min(ans,mi_water+landDuration[i]);
            }else{
                ans=min(ans,landStartTime[i]+landDuration[i]);
            }
        }
        return ans;
    }
};