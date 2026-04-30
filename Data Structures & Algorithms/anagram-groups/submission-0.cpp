#include <iostream>
#include <unordered_map>
class Solution {
public:
    void print2DVector(const vector<vector<string>>& vec) {
        for (const auto& row: vec) {
            cout << "[ ";
            for (const auto& s: row) {
                cout << s << " ";
            }
            cout << "]" << endl;
        }
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // for each str in strs, we need to sort them in ascending order.
        // Then, we need to sort the array one more time to place the similar
        // string next to each other, so that it is easier to append the result
        // at the end.
        // str that is similar (equal length and exact string after sorting)
        
        // base case: has 1 element
        vector<vector<string>> result;
        if (strs.size() == 1) {
            result.push_back(strs);
            return result;
        }

        vector<string> tempStrs;
        for (string str: strs) {
            sort(str.begin(), str.end());
            tempStrs.push_back(str);
        }
        unordered_map<string, vector<string>> groups;
        for (size_t i = 0; i < strs.size(); i++) {
            groups[tempStrs[i]].push_back(strs[i]);
        }

        for (const auto& [key, value]: groups) {
            result.push_back(value);
        }

        print2DVector(result);
        return result;
    }
};
