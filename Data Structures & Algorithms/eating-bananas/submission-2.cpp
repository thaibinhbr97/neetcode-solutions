class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int i = 1;
        int maxVal = *max_element(piles.begin(), piles.end());
        while (i < maxVal) {
            long long eatTime = 0;
            for (int pile: piles) {
                eatTime += (pile + i - 1) / i;
            }
            if (eatTime <= h) {
                return i;
            }
            i++;
        }
    }
};
