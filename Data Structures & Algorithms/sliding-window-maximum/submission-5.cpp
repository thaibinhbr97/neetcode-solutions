// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         // time: O(n*(n-k)), space: O(n)
//         vector<int> result;
//         int n = nums.size();
//         for (int i = 0; i < n - k + 1; i++) {
//             int maxSoFar = INT_MIN;
//             for (int j = i; j < i + k; j++) {
//                 maxSoFar = max(maxSoFar, nums[j]);
//             }
//             result.push_back(maxSoFar);
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // monotonically decreasing queue
        int l = 0;
        int r = 0;
        int n = nums.size();
        while (r < n) {
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);
            if (l > dq.front()) {
                dq.pop_front();
            }
            if (r - l + 1 >= k) {
                result.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }
        return result;
    }
};
