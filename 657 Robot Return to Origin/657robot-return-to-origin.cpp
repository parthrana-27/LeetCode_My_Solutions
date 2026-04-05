class Solution {
public:
    bool judgeCircle(string moves) {
        int n=moves.size();
        int h=0,v=0;
        for(int i=0;i<n;i++){
            char c=moves[i];
            if(c=='U') v--;
            else if(c=='D') v++;
            else if(c=='R') h++;
            else if(c=='L') h--;
        }
        if(h==0 && v==0) return true;
        return false;
    }
};