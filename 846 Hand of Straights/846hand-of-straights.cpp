class Solution {
public:
    bool isNStraightHand(vector<int>& hand,int gs) {
        int n=hand.size();
        if(n%gs !=0) return false;
        unordered_map<int,int>freq;
        for(int x:hand){
            freq[x]++;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &p:freq) pq.push(p.first);
            while(!pq.empty()){
                int s=pq.top();
                for(int i=0;i<gs;i++){
                    int c=s+i;
                    if(freq[c]==0){
                        return false;
                    }
                    freq[c]--;
                    if(freq[c]==0){
                        if(c != pq.top()){
                            return false;
                        }
                        pq.pop();
                    }
                }
            }
        return true;
    }
};