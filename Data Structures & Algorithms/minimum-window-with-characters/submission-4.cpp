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


// class Solution {
// public:
//     bool isValid(const string s, const string t, const unordered_map<char,int>& freqS, const unordered_map<char,int>& freqT) {
//         for (const auto& [c, count]: freqT) {
//             if (freqS.count(c) == 0 ||freqS.at(c) < count) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     // Time: O(n*m), space: O(n/m)
//     string minWindow(string s, string t) {
//         int n = s.size();
//         int m = t.size();

//         if (m == 0) {
//             return "";
//         }

//         unordered_map<char,int> countS;
//         unordered_map<char,int> countT;
        
//         for (char c: t) {
//             countT[c]++;
//         }

//         int resLen = INT_MAX;
//         pair<int,int> res = {-1,-1};
//         int l = 0;
//         int r = 0;
//         while (l < n && r < n) {
//             countS[s[r]]++;
//             while (l < n && isValid(s, t, countS, countT)) {
//                 if (r - l + 1 < resLen) {
//                     resLen = r - l + 1;
//                     res = {l, r};
//                 }
//                 countS[s[l]]--;
//                 l++;
//             }
//             r++;
//         }

//         if (resLen == INT_MAX) return "";
//         return s.substr(res.first, resLen);
//     }
// };

class Solution {
public:
    // Time: O(n), space: O(1)
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m == 0) {
            return "";
        }

        unordered_map<char,int> window;
        unordered_map<char,int> countT;
        
        for (char c: t) {
            countT[c]++;
        }

        int resLen = INT_MAX;
        pair<int,int> res = {-1,-1};
        int l = 0;
        int r = 0;
        int have = 0;
        int need = countT.size();
        while (l < n && r < n) {
            window[s[r]]++;
            if (countT.count(s[r]) && countT[s[r]] == window[s[r]]) {
                have++;
            }
            while (have == need) {
                if (r - l + 1 < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }
                window[s[l]]--;
                if (countT.count(s[l]) && countT[s[l]] > window[s[l]]) {
                    have--;
                }
                l++;
            }
            r++;
        }

        if (resLen == INT_MAX) return "";
        return s.substr(res.first, resLen);
    }
};



