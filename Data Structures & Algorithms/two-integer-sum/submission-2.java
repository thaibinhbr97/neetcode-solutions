class Solution {
    public int[] twoSum(int[] nums, int target) {
        // brute force
        // time: O(n^2), space: O(1)
        int[] result = new int[2];
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[]{i,j};
                }
            }
        }
        return new int[0];
    }
}
