class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // // time: O(n^2), space: O(n);
        // unordered_set<int> charSet;
        // int maxLength = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     for (int j = i; j < s.size(); j++) {
        //         // key exists
        //         if (charSet.find(s[j]) != charSet.end()) {
        //             break;
        //         } else {
        //             charSet.insert(s[j]);
        //             maxLength = max(maxLength, j - i + 1);
        //         }
        //     }
        //     charSet.clear();
        // }
        // return maxLength;

        // sliding window
        // time: O(n), space: O(m), n is the size of the string, m is the length of the longest substring
        // without duplicate characters -> O(n)
        unordered_set<int> charSet;
        int maxLength = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            // shrink the window by moving left pointer while key exists in charSet
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};
