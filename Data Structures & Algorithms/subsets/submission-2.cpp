class Solution {
public:
    void backtrack(const vector<int>& nums, int index, vector<vector<int>>& results, vector<int>& result) {
        if (index == nums.size()) {
            results.push_back(result);
            return;
        }
        result.push_back(nums[index]);
        backtrack(nums, index + 1, results, result);
        
        result.pop_back();

        backtrack(nums, index + 1, results, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;
        backtrack(nums, 0, results, result);
        return results;
    }
};
