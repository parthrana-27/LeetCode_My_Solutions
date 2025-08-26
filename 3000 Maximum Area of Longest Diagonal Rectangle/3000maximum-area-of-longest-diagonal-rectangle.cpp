class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int madiag=-1;
        int maarea=0;
        for(auto &d:dimensions)
        {
            int l=d[0];
            int w=d[1];
            int diag=l*l+w*w;
            int area=l*w;
            if(diag>madiag || diag==madiag && area> maarea){
                madiag=diag;
                maarea=area;
            }
        }
        return maarea;
    }
};