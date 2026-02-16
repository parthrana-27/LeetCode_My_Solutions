class Solution {
public:
    int numRabbits(vector<int>& ans){
        unordered_map<int,int>freq;
        for(int v:ans) freq[v]++;
        int res=0;
        for(auto [a,c]:freq){
            int group_size=a+1; 
            int groups=(c+group_size-1)/group_size;
            res+=groups*group_size;
        }
        return res;
    }
};