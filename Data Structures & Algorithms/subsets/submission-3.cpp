class Solution {
public:
    void backtrack(const vector<int>& nums, int index, vector<vector<int>>& result, vector<int>& subset) {
        if (index == nums.size()) {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        backtrack(nums, index + 1, result, subset);

        subset.pop_back();
        backtrack(nums, index + 1, result, subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(nums, 0, result, subset);
        return result;
    }
};
