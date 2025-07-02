class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        if(numRows==1 || numRows >=n) return s;
         vector<string> matrix(numRows);
        int i = 0, index = 0;
        bool direction = true;

        while (i < n) {
            matrix[index].push_back(s[i]);

            if (index == numRows - 1) direction = false;
            if (index == 0) direction = true;

            if (direction) index++;
            else index--;

            i++;
        }

        string result;
        for(auto &x:matrix)
        {
            result+=x;
        }

        return result;
    }
};