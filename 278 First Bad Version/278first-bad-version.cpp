// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    typedef long long ll;
    int firstBadVersion(int n) {
        ll l=1,h=n;
        while(l<=h){
            ll mid=(l+h)>>1;
            if(isBadVersion(mid)){
                h=mid-1;
            }else l=mid+1;
        }
        return l;
    }
};