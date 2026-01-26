class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mi=arr[1]-arr[0];
        int n=arr.size();
        vector<vector<int>>ans;
        ans.push_back({arr[0],arr[1]});
       
        for(int i=2;i<n;i++)
        {
            int diff=abs(arr[i]-arr[i-1]);
            if(diff<mi){
                mi=diff;
                while(!ans.empty()){
                ans.pop_back();
                }
                ans.push_back({arr[i-1],arr[i]});
            }else if(diff == mi) ans.push_back({arr[i-1],arr[i]});
        }
        return ans;
    }
};