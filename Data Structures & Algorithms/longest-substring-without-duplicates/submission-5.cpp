class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> charSet;
        int maxLength = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                // key exists
                if (charSet.find(s[j]) != charSet.end()) {
                    break;
                } else {
                    charSet.insert(s[j]);
                    maxLength = max(maxLength, j - i + 1);
                }
            }
            charSet.clear();
        }
        return maxLength;
    }
};
