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
       // Time: O(nlogn), Space: O(1)
    //    Arrays.sort(nums);
    //    for (int i = 1; i < nums.length; i++) {
    //     if (nums[i] == nums[i-1]) {
    //         return true;
    //     }
    //    }
    //    return false;

        // hash set
        // time: O(n), space: O(n)
        Set<Integer> seen = new HashSet<>();
        for (int num: nums) {
            if (seen.contains(num)) {
                return true;
            }
            seen.add(num);
        }
        return false;
    }
}
