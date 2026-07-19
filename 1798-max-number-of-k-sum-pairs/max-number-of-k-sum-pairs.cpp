class Solution {
public:
    int maxOperations(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int l=0,r=arr.size()-1;
        int cnt=0;
        while(l<r){
            int sum=arr[l]+arr[r];
            if(sum==k){
                cnt++;
                l++;
                r--;
            }
            else if(sum<k) l++;
            else r--;
        }
        return cnt;
    }
};