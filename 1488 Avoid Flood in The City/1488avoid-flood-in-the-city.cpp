class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        vector<int>res(n,-1);
        unordered_map<int,int>lastrain;
        set<int>dry;
        for(int i=0;i<n;i++)
        {
            int lake=rains[i];
            if(lake==0)
            {
                dry.insert(i);
                continue;
            }
            if(lastrain.count(lake)){
                auto it=dry.upper_bound(lastrain[lake]);
                if(it==dry.end()) return {};
                res[*it]=lake;
                dry.erase(it);
            }
            lastrain[lake]=i;
        }
        for(int i:dry) res[i]=1;
        return res;
    }
};