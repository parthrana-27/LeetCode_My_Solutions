class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int>q;
        vector<int>vis(n,0);
        vis[start]=1;
        q.push(start);
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            if(arr[idx]==0) return true;
            int idx1=idx+arr[idx];
            int idx2=idx-arr[idx];
            if(idx1<n && idx1>=0 && !vis[idx1]){
                if(arr[idx1]==0) return true;
                q.push(idx1);
                vis[idx1]=1;
            }
            if(idx2>=0 && idx2<n && !vis[idx2]){
                if(arr[idx2]==0) return true;
                q.push(idx2);
                vis[idx2]=1;
            }
        }
        return false;
    }
};