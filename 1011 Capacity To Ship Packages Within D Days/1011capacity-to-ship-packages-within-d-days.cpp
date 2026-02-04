class Solution {
    private:
    bool pos(vector<int>& w,int days,int mid){
        int use=1;
        int cur=0;
        for(int x:w){
            if(x>mid) return false;
            if(cur+x>mid){
                use++;
                cur=x;
            }else cur+=x;
        }
        return use <=days;
    }
public:
    int shipWithinDays(vector<int>& w, int days) {
        int ma=0;
        for(int i=0;i<w.size();i++){
            ma+=w[i];
        }
        int ans;
        int l=1,r=ma;
        while(l<=r){
            int mid=(l+r)/2;
            if(pos(w,days,mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};