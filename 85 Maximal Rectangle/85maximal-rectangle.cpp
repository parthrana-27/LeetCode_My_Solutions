class Solution {
public:
    int largest_hist(vector<int>& heights) {
       stack<int>st;
        int ma=0;
        int n=heights.size();
        for(int i=0;i<=n;i++){
            int curr=(i==n)?0:heights[i];

            while(!st.empty() && heights[st.top()]>curr) {
                int height=heights[st.top()];
                st.pop();
                int width=st.empty()?i:(i-st.top()-1);
                ma=max(ma,height*width);
            }

            st.push(i);
        }

        return ma;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ma=0;
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        for(int j=0;j<m;j++)
        {
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0') sum=0;
                prefix[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++)
        {
            ma=max(ma,largest_hist(prefix[i]));
        }
        return ma;
    }
};