class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r) {
            int total = numbers[l] + numbers[r];
            if (total == target) {
                break;
            } else if (total > target) {
                r--;
            } else {
                l++;
            }
        }
        // vector<int> result({l + 1, r + 1});
        return {l + 1, r + 1};
    }
};
