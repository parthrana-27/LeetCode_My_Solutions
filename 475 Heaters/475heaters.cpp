class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ma=0;
        int n=houses.size();
        int m=heaters.size();
        int j=0;
        for(int i=0;i<n;i++){
            int h=houses[i];
            while(j+1<m && abs(heaters[j+1]-h)<=abs(heaters[j]-h)){
                j++;
            }
            int dist=abs(heaters[j]-h);
            ma=max(ma,dist);
        }
        return ma;
    }
};