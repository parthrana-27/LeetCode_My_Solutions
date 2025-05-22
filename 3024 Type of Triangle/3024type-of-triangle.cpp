class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a=nums[0]+nums[1],b=nums[1]+nums[2],c=nums[0]+nums[2];
        if(a==b && a==c) return "equilateral";
        if(a>nums[2] && b > nums[0] && c> nums[1]){
        if(a==b || a==c || b==c) return "isosceles";
        else return "scalene";
        }
        return "none";
    }
};