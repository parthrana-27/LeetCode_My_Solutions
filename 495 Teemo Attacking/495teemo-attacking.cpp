class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int duration) {
        int n=t.size();
        int total=0;
        for(int i=0;i<n-1;i++)
        {
            if(t[i]+duration > t[i+1]){
                total+=t[i+1]-t[i];
            }else{
                total+=duration;
            }
        }
        return total+duration;
    }
};