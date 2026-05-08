class Solution {
public:
    int trap(vector<int>& height) {
        // O(n^2) for time, O(1) for space
        int n = height.size();
        int area = 0;
        for (int i = 0; i < n; i++) {
            int maxLeft = 0;
            int maxRight = 0;
            for (int j = i; j >= 0; j--) {
                maxLeft = max(maxLeft, height[j]);
            }
            for (int j = i; j < n; j++) {
                maxRight = max(maxRight, height[j]);
            }
            area += min(maxLeft, maxRight) - height[i];
        }
        return area;

        // // O(n) for time, O(1) for space
        // int left = 0;
        // int right = height.size() - 1;
        // int maxLeft = height[left];
        // int maxRight = height[right];
        // int area = 0;
        // while (left < right) {
        //     if (maxLeft < maxRight) {
        //         left++;
        //     } else {
        //         right--;
        //     }
        //     // water trapped from left
        //     if (height[left] < maxLeft) {
        //         area += maxLeft - height[left];
        //     } else {
        //         maxLeft = height[left];
        //     }
        //     // water trapped from right
        //     if (height[right] < maxRight) {
        //         area += maxRight - height[right];
        //     } else {
        //         maxRight = height[right];
        //     }
        // }
        // return area;
    }
};
