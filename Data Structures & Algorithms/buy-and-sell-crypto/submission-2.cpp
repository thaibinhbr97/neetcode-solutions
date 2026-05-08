class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // // brute force: O(n^2) time, O(1) space
        // int n = prices.size();
        // int maxSoFar = 0;
        // int maxProfit = 0;
        // for (int i = 0; i < n; i++) {
        //     int maxSoFar = 0;
        //     for (int j = i; j < n; j++) {
        //         maxSoFar = max(maxSoFar, prices[j]);
        //     }
        //     maxProfit = max(maxProfit, maxSoFar - prices[i]);
        // }
        // return maxProfit;

        // O(n) for time, O(1) for space
        int n = prices.size();
        int left = 0;
        int right = 1;
        int maxProfit = 0;
        int profit = 0;
        while (right < n) {
            if (prices[right] > prices[left]) {
                profit = prices[right] - prices[left];
                maxProfit = max(maxProfit, profit);
            } else {
                left = right;
            }
            right++;
        }
        return maxProfit;
    }
};
