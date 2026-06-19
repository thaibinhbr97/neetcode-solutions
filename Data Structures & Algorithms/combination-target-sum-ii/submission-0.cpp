class Solution {
public:
    void backtrack(const vector<int>& candidates, int target, int start, int curSum, vector<vector<int>>& result, vector<int>& combination) {
        if (curSum == target) {
            result.push_back(combination);
            return;
        }
        if (curSum > target) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) {
                continue;
            }
            if (curSum + candidates[i] > target) {
                break;
            }
            combination.push_back(candidates[i]);
            backtrack(candidates, target, i + 1, curSum + candidates[i], result, combination);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, 0, result, combination);
        return result;
    }
};
