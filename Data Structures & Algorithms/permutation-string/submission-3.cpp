#include <iostream>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // time: O(n * m), n is length of s2, m is length of s1
        // space: O(1)
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) {
            return false;
        }
        sort(s1.begin(), s1.end());
        for (int i = 0; i < n2 - n1 + 1; i++) {
            string temp = s2.substr(i, n1);
            cout << temp << endl;
            sort(temp.begin(), temp.end());
            cout << temp << endl;
            int count = 0;
            for (int j = 0; j < n1; j++) {
                if (s1[j] == temp[j]) {
                    count++;
                }
            }
            if (count == n1) {
                return true;
            }
        }
        return false;
    }
};
