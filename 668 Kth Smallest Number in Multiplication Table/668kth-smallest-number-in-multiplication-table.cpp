class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l=1,r=m*n,ans=-1;
        
        auto countLessEqual = [&](int x) {
            int cnt = 0;
            for (int i=1;i<=m;i++) {
                cnt += min(x/i,n); 
            }
            return cnt;
        };     
        while(l<=r){
            int mid = l+(r-l)/2;
            if (countLessEqual(mid) >= k) {
                ans = mid; 
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
