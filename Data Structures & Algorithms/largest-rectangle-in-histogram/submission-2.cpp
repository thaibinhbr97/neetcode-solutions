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
        int size = heights.size();
        vector<pair<int, int>> indexBounds(size, {0, 0});
        int result = 0;
        // check to the left
        for (int i = 0; i < size; i++) {
            int leftIdx = i;
            while (leftIdx >= 0 && heights[i] <= heights[leftIdx]) {
                leftIdx--;
            }
            indexBounds[i].first = max(leftIdx + 1, 0);
        }
        // check to the right
        for (int i = 0; i < size; i++) {
            int rightIdx = i;
            while (rightIdx < size && heights[i] <= heights[rightIdx]) {
                rightIdx++;
            }
            indexBounds[i].second = min(rightIdx - 1, size - 1);
        }
        for (int i = 0; i < size; i++) {
            result = max(result, heights[i] * (indexBounds[i].second - indexBounds[i].first + 1));
        }
        return result;
    }
};
