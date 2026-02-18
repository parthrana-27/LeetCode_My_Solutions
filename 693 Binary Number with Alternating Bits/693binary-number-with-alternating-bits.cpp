class Solution {
public:
    bool hasAlternatingBits(int n) {
        int p=-1;
        while(n>0){
            int c=n&1;
            if(c==p) return false;
            p=c;
            n>>=1;
        }
        return true;
    }
};