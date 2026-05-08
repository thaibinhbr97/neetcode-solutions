class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = height[left];
        int maxRight = height[right];
        int area = 0;
        while (left < right) {
            if (maxLeft < maxRight) {
                left++;
            } else {
                right--;
            }
            // water trapped from left
            if (height[left] < maxLeft) {
                area += maxLeft - height[left];
            } else {
                maxLeft = height[left];
            }
            // water trapped from right
            if (height[right] < maxRight) {
                area += maxRight - height[right];
            } else {
                maxRight = height[right];
            }
        }
        return area;
    }
};
