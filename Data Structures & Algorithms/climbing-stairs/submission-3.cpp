class Solution {
public:
    int climbStairs(int n) {
        // 1 -> 1 way
        // 2 -> (0 -> 2) + (0 -> 1 -> 2) = 2
        // 3 -> (1 -> 3) + (1 -> 2 -> 3) + (2 -> 3) = 3

        // dp - bottom up
        if (n <= 2) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
