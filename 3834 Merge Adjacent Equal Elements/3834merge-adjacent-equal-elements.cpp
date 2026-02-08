class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        stack<long long>st;
        for(int i=0;i<n;i++){
            long long x=nums[i];
            while(!st.empty() && st.top()==x){
                st.pop();
                x*=2;
            }
            st.push(x);
        }
        vector<long long>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};