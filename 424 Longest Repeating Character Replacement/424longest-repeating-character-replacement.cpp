class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0;
        int ma=0;
        int mf=0;
        int hash[26]={0};
        int n=s.length();
        while(r<n)
        {
            hash[s[r]-'A']++;
            mf=max(mf,hash[s[r]-'A']);
             if ((r - l + 1) - mf > k) {
                hash[s[l] - 'A']--;
                l++;
            }
            ma = max(ma, r - l + 1);
            r++;
        }

        return ma;
    }
};