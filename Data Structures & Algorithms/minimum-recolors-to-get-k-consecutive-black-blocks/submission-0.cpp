class Solution {
public:
// WBBWWBBWBW
//    l
//     r
// left = 0
// right = 0
// operations = 0
// result = 0

    int minimumRecolors(string blocks, int k) {
        int left = 0;
        int right = 0;
        int operations = 0;
        int result = 0;
        while (right < k) {
            if (blocks[right] == 'W') {
                operations++;
            }
            right++;
        }
        // window of size k
        int n = blocks.size();
        result = operations;
        cout << operations << endl;
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