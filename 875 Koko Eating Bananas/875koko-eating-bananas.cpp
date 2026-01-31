class Solution {
    private:
    int f(vector<int>&v){
        int ma=INT_MIN;
        int n=v.size();
        for(int i=0;i<n;i++){
            ma=max(ma,v[i]);
        }
        return ma;
    }
    long long cal(vector<int>&v,int mid){
        long long t=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            t+=ceil(double(v[i])/(double)mid);
        }
        return t;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l=1,r=f(piles);
        while(l<=r){
            long long mid=(l+r)/2;
            long long t=cal(piles,mid);
            if(t<=h){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return (int)l;
    }
};