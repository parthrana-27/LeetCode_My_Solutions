class Solution {
public:
    int maxDistance(string str, int k) {
        int ans=0;
        int n=0,s=0,w=0,e=0;

        for(int i=0;i<str.size();i++)
        {
            char ch=str[i];
            if(ch=='N') n++;
            else if(ch=='S') s++;
            else if(ch=='E') e++;
            else w++;
            int x=abs(n-s);
            int y=abs(e-w);
            int md=x+y;
            int dis=md+min(2*k,i+1-md);
            ans=max(ans,dis);
        }
        return ans;
    }
};