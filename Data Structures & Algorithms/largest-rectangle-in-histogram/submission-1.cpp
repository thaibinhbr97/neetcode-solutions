class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> incStack; // pair: <index, height>
        int size = heights.size();
        for (int i = 0; i < size; i++) {
            int h = heights[i];
            int start = i;
            while (!incStack.empty() && incStack.top().second > h) {
                auto [index, height] = incStack.top();
                incStack.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            incStack.push({start, h});
        }
        while (!incStack.empty()) {
            auto [index, height] = incStack.top();
            incStack.pop();
            maxArea = max(maxArea, height * (size - index));
        }
        return maxArea;
    }
};
