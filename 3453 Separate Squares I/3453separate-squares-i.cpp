class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double t=0.0;
        double low=1e18,high=-1e18;
        for(auto &s:squares){
            double y=s[1],l=s[2];
            t+=l*l;
            low=min(low,y);
            high=max(high,y+l);
        }
        double tar=t/2.0;
        auto areabelow=[&](double y){
            double area=0.0;
            for(auto& s:squares){
            double yi=s[1],l=s[2];
            if(y<=yi) continue;
            else if(y>=yi+l) area+=l*l;
            else area+=l*(y-yi);
        }
        return area;
        };
        for(int i=0;i<60;i++){
            double mid=(low+high)/2.0;
            if(areabelow(mid)<tar)
                low=mid;
                else high=mid;
        }
            return (low+high)/2.0;
    }
};