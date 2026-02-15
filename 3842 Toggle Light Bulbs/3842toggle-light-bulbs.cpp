class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool>on(101,0);
        int n=bulbs.size();
        for(int i=0;i<n;i++){
            on[bulbs[i]]=!on[bulbs[i]];
        }
        vector<int>res;
        for(int i=1;i<=100;i++){
            if(on[i]) res.push_back(i);
        }
        return res;
    }
};