class Solution {
public:
    int climbStairs(int n) {
        // 1 -> 1 way
        // 2 -> (0 -> 2) + (0 -> 1 -> 2) = 2
        // 3 -> (1 -> 3) + (1 -> 2 -> 3) + (2 -> 3) = 3

        // // dp - bottom up
        // // time: O(n), only compute dp[i] once since storing in the array and the i depends on i - 1 and i - 2
        // // space: O(n)
        // if (n <= 2) return n;
        // vector<int> dp(n + 1);
        // dp[1] = 1;
        // dp[2] = 2;
        // for (int i = 3; i <= n; i++) {
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];

        if (n <= 2) return n;
        int prev = 1;
        int curr = 2;
        for (int i = 3; i <= n; i++) {
            int next = prev + curr;
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
