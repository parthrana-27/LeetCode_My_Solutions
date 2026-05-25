class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        if(s[n-1]=='1') return false;
        queue<int>q;
        q.push(0);
        int far=0;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            int st=max(i+minJump,far+1);
            int e=min(i+maxJump,n-1);
            for(int j=st;j<=e;j++){
                if(s[j]=='0'){
                    if(j==n-1) return true;
                    q.push(j);
                }
            }
            far=max(far,e);
        }
        return false;
    }
};