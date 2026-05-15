class Solution {
public:
    int findMin(vector<int> &nums) {
        // [3,4,5,6,1,2]
        // decreasing at 1 point -> split into two sub array

        // [1] -> only return
        // [1,2] -> 1
        // [2,1] -> 1
        // [7,9,1,3,5]
        // left < mid < right + ascending order
        // [1,2,3,4,5,6]
        // mid < right, mid <   
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
