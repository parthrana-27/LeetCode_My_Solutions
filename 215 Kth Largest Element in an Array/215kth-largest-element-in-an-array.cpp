class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>mi;
        for(int n:nums){
            mi.push(n);
            if(mi.size()>k){
                mi.pop();
            }
        }
        return mi.top();
    }
};