
class Solution {
public:
    bool isPalindrome(string s) {
        string so;
        for (char ch : s) {
            if (isalnum(ch)) {
                so += tolower(ch);
            }
        }
        int left = 0, right = so.size() - 1;
        while (left < right) {
            if (so[left] != so[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
