class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        int m=potions.size();
        sort(potions.begin(),potions.end());
        for(int s:spells){
            int l=0,r=m-1,idx=m;
            while(l<=r){
                int mid=l+(r-l)/2;
                if((long long)s*potions[mid]>=success){
                    idx=mid;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            ans.push_back(m-idx);
        }
        return ans;
    }
};