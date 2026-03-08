class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(n==1) return 0;
        if(n==2){
            if(s[0]>s[1]) return -1;
            else return 0;
        }
        string t=s;
        sort(t.begin(),t.end());
        if(s==t) return 0;
        string s_1=s;
        string s_2=s;

        sort(s_1.begin(),s_1.begin()+n-1);
        sort(s_2.begin()+1,s_2.end());

        if(s_1==t || s_2==t){
            return 1;
        }
        sort(s_1.begin()+1,s_1.end());
        sort(s_2.begin(),s_2.begin()+n-1);
        if(s_1 == t|| s_2 == t){
            return 2;
        }
        else{
            return 3;
        }
    }
};