class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        colors.insert(colors.end(),colors.begin(),colors.begin()+(k-1));
        int c=0;
        int l=0;
        for(int i=0;i<colors.size();++i)
        {
            if(i>0 && colors[i]==colors[i-1])
            {
                l=i;
            }
            if(i-l+1>=k)
            {
                c++;
            }
        }
        return c;
    }
};