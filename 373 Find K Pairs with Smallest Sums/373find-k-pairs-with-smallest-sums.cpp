class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>res;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({nums1[0]+nums2[0],{0,0}});
        while(!pq.empty() && k>0){
            auto [sum,ind]=pq.top();
            pq.pop();
            int i=ind.first;
            int j=ind.second;
            res.push_back({nums1[i],nums2[j]});
            k--;
            if(j+1<nums2.size()){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
            if(j==0 && i+1<nums1.size()){
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
            }
        }
        return res;
    }
};