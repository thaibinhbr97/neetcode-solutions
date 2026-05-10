class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqMap;
        int maxLength = 0;
        for (int i = 0; i < s.size(); i++) {
            int maxFreq = 0;
            for (int j = i; j < s.size(); j++) {
                freqMap[s[j]]++;
                maxFreq = max(maxFreq, freqMap[s[j]]);
                if ((j - i + 1) - maxFreq <= k) {
                    maxLength = max(maxLength, j - i + 1);
                } else {
                    break;
                }
            }
            freqMap.clear();
        }
        return maxLength;
    }
};
