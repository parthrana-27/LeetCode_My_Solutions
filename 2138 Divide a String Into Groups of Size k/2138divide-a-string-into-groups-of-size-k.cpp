class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        int group=(n+k-1)/k;
        vector<string>ans(group);
        for(int i=0;i<group;i++)
        {
            string temp;
            for(int j=0;j<k;j++)
            {
                int idx=i*k+j;
                if(idx<n){
                    temp+=s[idx];
                }else{
                    temp+=fill;
                }
            }
            ans[i]=temp;
        }
        return ans;
    }
};