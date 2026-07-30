class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m == 0) return "";

        pair<int,int> res = {-1, -1};
        int resLen = INT_MAX;
        unordered_map<char,int> tCount;
        unordered_map<char,int> sCount;
        
        for (char c: t) {
            tCount[c]++;
        }
        
        for (int i = 0; i < n; i++) {
            sCount.clear();
            for (int j = i; j < n; j++) {
                sCount[s[j]]++;

                bool flag = true;
                for (auto& p: tCount) {
                    char c = p.first;
                    if (sCount[c] < tCount[c]) {
                        flag = false;
                        break;
                    }
                }

                if (flag && (j - i + 1) < resLen) {
                    resLen = j - i + 1;
                    res = {i, j};
                }
            }
        }
        if (resLen == INT_MAX) return "";
        return s.substr(res.first, resLen);
    }
};
