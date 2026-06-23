class Solution {
public:
    void backtrack(const vector<int>& nums, int start, vector<vector<int>>& result, vector<int>& subset) {
        if (start == nums.size()) {
            result.push_back(subset);
            return;
        }
        // include the current num from nums
        subset.push_back(nums[start]);
        backtrack(nums, start + 1, result, subset);
        subset.pop_back();

        // skip the duplicates since solution must not contain duplicate subsets
        while (start + 1 < nums.size() && nums[start] == nums[start + 1]) {
            start++;
        }
        
        // exclude the current num from nums
        backtrack(nums, start + 1, result, subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, result, subset);
        return result;
    }
};
