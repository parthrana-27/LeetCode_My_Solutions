class Solution {
    private:
    bool pos(int mid,int m,int k,vector<int>&b){
        int c=0;
        int no_b=0;
        for(int i=0;i<b.size();i++){
            if(b[i]<=mid){
                c++;
            }
            else{
                no_b+=(c/k);
                c=0;
            }
        }
        no_b+=(c/k);
        return no_b>=m;
    }
public:
    int minDays(vector<int>& b, int m, int k) {
        long long v=1LL*m*k;
        if(v>b.size()) return -1;
        int mi=INT_MAX;
        int ma=INT_MIN;
        for(int i=0;i<b.size();i++){
            mi=min(mi,b[i]);
            ma=max(ma,b[i]);
        }
        int l=mi,r=ma;
        while(l<=r){
            int mid=(l+r)/2;
            if(pos(mid,m,k,b)){
                r=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};