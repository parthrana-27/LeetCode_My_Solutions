class Solution {
public:
    int countMonobit(int n) {
        int c=1;
        long long val=1;
        while(val<=n){
            c++;
            val=(val<<1)|1;
        }
        return c;
    }
};