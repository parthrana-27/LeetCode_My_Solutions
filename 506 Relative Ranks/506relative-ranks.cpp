class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        int n=score.size();
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        vector<string>ans(n);
        int rank=1;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            if(rank==1) ans[x.second]="Gold Medal";
            else if(rank==2) ans[x.second]="Silver Medal";
            else if(rank==3) ans[x.second]="Bronze Medal";
            else ans[x.second]=to_string(rank);
            rank++;
            }
            return ans;
    }
};