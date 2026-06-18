class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m=minutes*6.0; // 360/60=6
        double h=(hour%12)*30.0+minutes*0.5; // 360/12=30 + 30/60=0.5
        double diff=abs(h-m);
        return min(diff,360-diff);
    }
};