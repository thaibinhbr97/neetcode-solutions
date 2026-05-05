#include <cctype>
class Solution {
public:
    bool isAlphanumeric(char c) {
        return (c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9');
    }
    // time: O(n)
    // space: O(1)
    // bool isPalindrome(string s) {
    //     int l = 0;
    //     int r = s.size() - 1;
    //     while (l < r) {
    //         if (!isAlphanumeric(s[l])) {
    //             l++;
    //         } else if (!isAlphanumeric(s[r])) {
    //             r--;
    //         } else {
    //             if (tolower(s[l]) != tolower(s[r])) {
    //                 return false;
    //             }
    //             l++;
    //             r--;
    //         }
    //     }
    //     return true;
    // }

    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (!isdigit(s[l]) && !isalpha(s[l])) {
                l++;
            } else if (!isdigit(s[r]) && !isalpha(s[r])) {
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
