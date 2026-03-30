class Solution {
    public int[] twoSum(int[] nums, int target) {
        // brute force
        int[] result = new int[2];
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                result[0] = i;
                result[1] = j;
                System.out.println(result);
                if (i != j && nums[i] + nums[j] == target) {
                    return result;
                }
            }
        }
        return null;
    }
}
