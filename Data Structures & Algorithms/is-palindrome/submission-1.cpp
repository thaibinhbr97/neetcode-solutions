#include <cctype>
class Solution {
public:
    bool isAlphanumeric(char c) {
        return (c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (!isAlphanumeric(s[l])) {
                l++;
            } else if (!isAlphanumeric(s[r])) {
                r--;
            } else {
                if (tolower(s[l]) != tolower(s[r])) {
                    return false;
                }
                l++;
                r--;
            }
        }
        return true;
    }
};
