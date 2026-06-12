class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // // sorting
        // // time: O(nlogn)
        // // space: O(1)
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() - k];

        // max heap
        // time: O(nlogn)
        // space: O(n)
        priority_queue<int> maxHeap;
        for (int num: nums) {
            maxHeap.push(num);
        }
        int i = 0;
        while (i < k - 1) {
            maxHeap.pop();
            i++;
        }
        return maxHeap.top();
    }
};
