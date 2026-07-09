class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0;
        int right = 0;
        int operations = 0;
        while (right < k) {
            if (blocks[right] == 'W') {
                operations++;
            }
            right++;
        }
        // window of size k
        int n = blocks.size();
        int result = operations;
        while (right < n) {
            if (blocks[right] == 'W') {
                operations++;
            }
            if (blocks[left] == 'W') {
                operations--;
            }
            result = min(result, operations);
            right++;
            left++;
        }
        return result;
    }
};