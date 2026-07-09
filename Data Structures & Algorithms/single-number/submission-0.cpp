class Solution {
public:
    int singleNumber(vector<int>& nums) {
//     3       2       3       
//     0011    0010    0011

// XOR 0000    0011    0001
//     0011    0001    0010
        int res = 0;
        for (int num: nums) {
            res ^= num;
        }
        return res;
    }
};
