class Solution {
    public boolean hasDuplicate(int[] nums) {
        // brute force
        // time: O(n^2), space: O(1)
    //     for (int i = 0; i < nums.length; i++) {
    //         for (int j = i + 1; j < nums.length; j++) {
    //             if (nums[i] == nums[j]) {
    //                 return true;
    //             }
    //         }
    //     }
    //    return false;

       // sorting
       Arrays.sort(nums);
       for (int i = 1; i < nums.length; i++) {
        if (nums[i] == nums[i-1]) {
            return true;
        }
       }
       return false;
    }
}
