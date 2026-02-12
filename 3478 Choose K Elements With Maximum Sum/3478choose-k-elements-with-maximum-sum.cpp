class Solution {
public:
    typedef long long ll;
    vector<long long> findMaxSum(vector<int>& n1, vector<int>& n2, int k) {
        int n=n1.size();
        vector<ll>ans(n,0);
        vector<vector<int>>a;
        for(int i=0;i<n;i++){
            a.push_back({n1[i],n2[i],i});
        }

        sort(a.begin(),a.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        ll s=0;
        int i=0;
        while(i<n){
            int j=i;
            while(j<n && a[j][0]==a[i][0]){
                ans[a[j][2]]=s;
                j++;
            }
            for(int t=i;t<j;t++){
                int v2=a[t][1];

                if((int)pq.size()<k){
                    pq.push(v2);
                    s+=v2;
                }else if(k>0 && v2 > pq.top()){
                    s-=pq.top();
                    pq.pop();
                    pq.push(v2);
                    s+=v2;
                }
            }
            i=j;
        }
        return ans;
    }
};