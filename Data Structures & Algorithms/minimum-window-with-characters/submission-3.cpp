// class Solution {
// public:
//     // Time: O(n^2), space: O(n)
//     string minWindow(string s, string t) {
//         int n = s.size();
//         int m = t.size();

//         if (m == 0) return "";

//         pair<int,int> res = {-1, -1};
//         int resLen = INT_MAX;
//         unordered_map<char,int> tCount;
//         unordered_map<char,int> sCount;
        
//         for (char c: t) {
//             tCount[c]++;
//         }
        
//         for (int i = 0; i < n; i++) {
//             sCount.clear();
//             for (int j = i; j < n; j++) {
//                 sCount[s[j]]++;

//                 bool flag = true;
//                 for (auto& p: tCount) {
//                     char c = p.first;
//                     if (sCount[c] < tCount[c]) {
//                         flag = false;
//                         break;
//                     }
//                 }

//                 if (flag && (j - i + 1) < resLen) {
//                     resLen = j - i + 1;
//                     res = {i, j};
//                 }
//             }
//         }
//         if (resLen == INT_MAX) return "";
//         return s.substr(res.first, resLen);
//     }
// };


class Solution {
public:
    bool isValid(const string s, const string t, unordered_map<char,int>& freqS, unordered_map<char,int>& freqT) {
        for (auto& [c, count]: freqT) {
            if (freqS[c] < count) {
                return false;
            }
        }
        return true;
    }

    // Time: O(n), space: O(n)
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m == 0) {
            return "";
        }

        unordered_map<char,int> countS;
        unordered_map<char,int> countT;
        
        for (char c: t) {
            countT[c]++;
        }

        int resLen = INT_MAX;
        pair<int,int> res = {-1,-1};
        int l = 0;
        int r = 0;
        while (l < n && r < n) {
            countS[s[r]]++;
            while (l < n && isValid(s, t, countS, countT)) {
                if (r - l + 1 < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }
                countS[s[l]]--;
                l++;
            }
            r++;
        }

        if (resLen == INT_MAX) return "";
        return s.substr(res.first, resLen);
    }
};
