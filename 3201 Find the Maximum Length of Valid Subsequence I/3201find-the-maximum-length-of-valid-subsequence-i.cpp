class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0,odd=0;
        int altodd=0,alteven=0;
        for(int num:nums)
        {
            int p=num%2;
            if(p==0)
            {
                even++;
                alteven=altodd+1;
            }else{
                odd++;
                altodd=alteven+1;
            }
        }
        return max({even,odd,altodd,alteven});
    }
};