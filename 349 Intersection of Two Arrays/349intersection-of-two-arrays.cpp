class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st(begin(nums1),end(nums1));
        vector<int>result;
        for(int no:nums2)
        {
            if(st.find(no)!=st.end())
            {
                result.push_back(no);
                st.erase(no);
            }
        }
        return result;
        

    }
};