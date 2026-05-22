class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n=cit.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int papers=n-mid;
            if(cit[mid]>=papers){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return n-l;
    }
};