class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n - k + 1; i++) {
            int maxSoFar = INT_MIN;
            for (int j = i; j < i + k; j++) {
                maxSoFar = max(maxSoFar, nums[j]);
            }
            result.push_back(maxSoFar);
        }
        return result;
    }
};
