class Solution {
public:
    int characterReplacement(string s, int k) {
        // // brute force
        // // time: O(n^2), space: O(26) ~ O(1), n: is length of string
        // unordered_map<char, int> freqMap;
        // int maxLength = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     int maxFreq = 0;
        //     for (int j = i; j < s.size(); j++) {
        //         freqMap[s[j]]++;
        //         maxFreq = max(maxFreq, freqMap[s[j]]);
        //         if ((j - i + 1) - maxFreq <= k) {
        //             maxLength = max(maxLength, j - i + 1);
        //         } else {
        //             break;
        //         }
        //     }
        //     freqMap.clear();
        // }
        // return maxLength;

        // sliding window
        unordered_map<char, int> freqMap;
        int maxLength = 0;
        int l = 0;
        int maxFreq = 0;
        for (int r = 0; r < s.size(); r++) {
            freqMap[s[r]]++;
            maxFreq = max(maxFreq, freqMap[s[r]]);
            if ((r - l + 1) - maxFreq <= k) {
                maxLength = max(maxLength, r - l + 1);
            } else {
                while ((r - l + 1) - maxFreq > k) {
                    freqMap[s[l]]--;
                    l++;
                }
            }
        }
        return maxLength;
    }
};
