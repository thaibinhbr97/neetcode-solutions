class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        long long product = 1;
        long long productWithoutZero = 1;
        int zeroCount = 0;
        for (int num: nums) {
            if (num != 0) {
                productWithoutZero *= num;
            } else {
                zeroCount++;
            }
            product *= num;
        }
        // at least 1 0's in nums
        if (product == 0) {
            for (int num: nums) {
                // cout << num << endl;
                // cout << product << endl;
                // cout << productWithoutZero << endl;
                // cout << zeroCount << '\n' << endl;
                if (num == 0) {
                    if (zeroCount > 1) {
                        result.push_back(0);
                    } else { // zeroCount == 1
                        result.push_back(productWithoutZero);
                    }
                } else {
                    result.push_back(0);
                }
            }
        // there is no 0's in nums            
        } else {
            for (int num: nums) {
                result.push_back(product / num);
            }
        }
        return result;
    }
};
