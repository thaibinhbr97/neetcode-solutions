class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxSoFar = 0;
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            int maxSoFar = 0;
            for (int j = i; j < n; j++) {
                maxSoFar = max(maxSoFar, prices[j]);
            }
            maxProfit = max(maxProfit, maxSoFar - prices[i]);
        }
        return maxProfit;
    }
};
