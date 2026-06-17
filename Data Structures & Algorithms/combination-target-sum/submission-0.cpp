class Solution {
public:
    void backtrack(const vector<int>& nums, int target, int index, int curSum, vector<vector<int>>& result, vector<int>& option) {
        // base case: if the result is found, add to the result
        if (curSum == target) {
            result.push_back(option);
            return;
        } 
        // if we overadd or run out of numbers, return
        if (curSum > target || index >= nums.size()) {
            return;
        }

        // two cases: 
        // 1. include the current element, but stay on the same index
        option.push_back(nums[index]);
        backtrack(nums, target, index, curSum + nums[index], result, option);
        option.pop_back();

        // 2. exclude the current element, and move to the next index
        backtrack(nums, target, index + 1, curSum, result, option);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> option;
        backtrack(nums, target, 0, 0, result, option);
        return result;
    }
};
