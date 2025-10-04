class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int m=0;
        while(l<r)
        {
            int len=min(height[l],height[r]);
            int area=len*(r-l);
            m=max(m,area);
           if(height[l]<height[r]) l++;
           else r--;
        }
        return m;
    }
};