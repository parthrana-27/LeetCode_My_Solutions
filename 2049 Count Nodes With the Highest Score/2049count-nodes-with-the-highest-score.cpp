class Solution {
public:
    vector<vector<int>>children;
    long long ma=0;
    int cntm=0;
    int n;
    int dfs(int node){
        long long score=1;
        int s=1;
        for(int child:children[node]){
            int c_size=dfs(child);
            s+=c_size;
            score*=c_size;
        }
        int rest=n-s;
        if (rest>0) score*=rest;
        if (score>ma) {
            ma=score;
            cntm=1;
        }else if(score==ma) {
            cntm++;
        }
        return s;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        n=parents.size();
        children.resize(n);
        for (int i=1;i<n;i++) children[parents[i]].push_back(i);
        dfs(0);
        return cntm;
    }
};