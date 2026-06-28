class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if(arr[0]!=1) arr[0]=1;
        for(int i=1;i<n;i++){
            arr[i]=min(arr[i],arr[i-1]+1);
        }
        return arr.back();
    }
};