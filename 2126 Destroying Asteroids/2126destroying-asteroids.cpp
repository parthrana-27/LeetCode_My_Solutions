class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        long long cur=mass;
        for(int as:asteroids){
            if(cur<as){
                return false; 
            }
            cur+=as;
        }
        return true;
    }
};