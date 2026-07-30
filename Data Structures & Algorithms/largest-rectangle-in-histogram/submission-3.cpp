// class Solution {
// public:
//     // Time: O(n), Space: O(n)
//     int largestRectangleArea(vector<int>& heights) {
//         int maxArea = 0;
//         stack<pair<int, int>> incStack; // pair: <index, height>
//         int size = heights.size();
//         for (int i = 0; i < size; i++) {
//             int h = heights[i];
//             int start = i;
//             while (!incStack.empty() && incStack.top().second > h) {
//                 auto [index, height] = incStack.top();
//                 incStack.pop();
//                 maxArea = max(maxArea, height * (i - index));
//                 start = index;
//             }
//             incStack.push({start, h});
//         }
//         while (!incStack.empty()) {
//             auto [index, height] = incStack.top();
//             incStack.pop();
//             maxArea = max(maxArea, height * (size - index));
//         }
//         return maxArea;
//     }
// };


class Solution {
public:
    // Time: O(n^2), Space: O(n)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int leftIdx = i;
            int rightIdx = i;

            while (leftIdx >= 0 && heights[i] <= heights[leftIdx]) {
                leftIdx--;
            }

            while (rightIdx < n && heights[i] <= heights[rightIdx]) {
                rightIdx++;
            }

            int width = (rightIdx - 1) - (leftIdx + 1) + 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }
};
