#include <iostream>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // // sorting similar in anagram
        // // time: O(n * m), n is length of s2, m is length of s1
        // // space: max(O(n), O(m));
        // int n1 = s1.size();
        // int n2 = s2.size();
        // if (n1 > n2) {
        //     return false;
        // }
        // sort(s1.begin(), s1.end());
        // for (int i = 0; i < n2 - n1 + 1; i++) {
        //     string temp = s2.substr(i, n1);
        //     sort(temp.begin(), temp.end());
        //     int count = 0;
        //     for (int j = 0; j < n1; j++) {
        //         if (s1[j] == temp[j]) {
        //             count++;
        //         }
        //     }
        //     if (count == n1) {
        //         return true;
        //     }
        // }
        // return false;

        // // sliding window and hash table approach
        // // time: O(m * n), n: length of s1, m: length of s2
        // // space: O(n)
        // // abbaac, baa len of window: 3 -> cannot use set (counter example)
        // // a,b | a,b
        // int n1 = s1.size();
        // int n2 = s2.size();
        // if (n1 > n2) {
        //     return false;
        // }
        // unordered_map<char, int> freqCount1;
        // for (char c: s1) {
        //     freqCount1[c]++;
        // }
        // unordered_map<char, int> freqCount2;
        // int l = 0;
        // for (int r = 0; r < n2; r++) {
        //     if (r - l + 1 < n1) {
        //         freqCount2[s2[r]]++;
        //         continue;           
        //     } else {  
        //         freqCount2[s2[r]]++;                 
        //         int count = 0;
        //         for (char c: s1) {
        //             if (freqCount2.contains(c) && freqCount1[c] == freqCount2[c]) {
        //                 count++;
        //             }
        //         }
        //         if (count == n1) {
        //             return true;
        //         }
        //         freqCount2[s2[l]]--;
        //         l++;                
        //     }
        // }
        // return false;

        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) {
            return false;
        }
        array<int, 26> freqCount1 = {0};
        array<int, 26> freqCount2 = {0};
        for (int i = 0; i < n1; i++) {
            freqCount1[s1[i] - 'a']++;
            freqCount2[s2[i] - 'a']++;
        }
        if (freqCount1 == freqCount2) return true;
        int l = 0;
        for (int r = n1; r < n2; r++) {
            freqCount2[s2[r] - 'a']++;
            freqCount2[s2[l] - 'a']--;
            l++;
            if (freqCount1 == freqCount2) return true;
        }
        return false;
    }
};
