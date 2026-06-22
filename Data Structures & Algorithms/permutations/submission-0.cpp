class Solution {
public:
    void backtrack(const vector<int>& nums, vector<vector<int>>& result, vector<int>& path, vector<bool>& visited) {
        if (nums.size() == path.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;

            path.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, result, path, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        
        backtrack(nums, result, path, visited);
        return result;
    }
};
