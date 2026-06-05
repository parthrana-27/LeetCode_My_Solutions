class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<tuple<double,int,int>,vector<tuple<double,int,int>>,greater<tuple<double,int,int>>>mi;
        for(int j=1;j<n;j++){
            mi.push({(double)arr[0]/arr[j],0,j});
        }
        for(int i=0;i<k;i++){
            auto [v,i_ind,j_ind]=mi.top();
            mi.pop();
            if(i==k-1){
                return {arr[i_ind],arr[j_ind]};
            }
            if(i_ind+1<j_ind){
                mi.push({(double)arr[i_ind+1]/arr[j_ind],i_ind+1,j_ind});
            }
        }
        return {};
    }
};