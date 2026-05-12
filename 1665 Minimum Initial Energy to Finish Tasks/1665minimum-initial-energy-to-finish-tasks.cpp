class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](const vector<int>&a,const vector<int>& b){
            return (a[1]-a[0])>(b[1]-b[0]);
        });
        int init=0;
        int cur=0;
        for(auto& p:tasks){
            int actual=p[0];
            int mi=p[1];
            if(cur<mi){
                init+=(mi-cur);
                cur=mi;
            }
            cur-=actual;
        }
        return init;
    }
};