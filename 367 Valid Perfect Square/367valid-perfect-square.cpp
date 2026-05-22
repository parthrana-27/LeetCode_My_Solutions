class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1,r=num;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long res=1LL*mid*mid;
            if(res==num) return true;
            else if(res>num){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
};