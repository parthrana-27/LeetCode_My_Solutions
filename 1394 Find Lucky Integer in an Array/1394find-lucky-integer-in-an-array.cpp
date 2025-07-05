class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>freq;
        int l=-1;
        for(int i=0;i<arr.size();i++)
        {
            freq[arr[i]]++;
        }
        for(auto& num:freq)
        {
            if(num.first==num.second)
            {
                l=max(l,num.first);
            }
        }
        return l;
    }
};