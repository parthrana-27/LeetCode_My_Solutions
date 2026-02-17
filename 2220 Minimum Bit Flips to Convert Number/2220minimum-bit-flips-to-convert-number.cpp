class Solution {
public:
    int minBitFlips(int start, int goal) {
        int v=start^goal;
        int c=0;
        while(v>0){
            c+=(v&1);
            v>>=1;
        }
        return c;
    }
};