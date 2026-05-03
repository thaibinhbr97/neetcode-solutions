class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // // O(n) time but with division, O(n) space for result
        // vector<int> result;
        // long long product = 1;
        // long long productWithoutZero = 1;
        // int zeroCount = 0;
        // for (int num: nums) {
        //     if (num != 0) {
        //         productWithoutZero *= num;
        //     } else {
        //         zeroCount++;
        //     }
        //     product *= num;
        // }
        // // at least 1 0's in nums
        // if (product == 0) {
        //     for (int num: nums) {
        //         // cout << num << endl;
        //         // cout << product << endl;
        //         // cout << productWithoutZero << endl;
        //         // cout << zeroCount << '\n' << endl;
        //         if (num == 0) {
        //             if (zeroCount > 1) {
        //                 result.push_back(0);
        //             } else { // zeroCount == 1
        //                 result.push_back(productWithoutZero);
        //             }
        //         } else {
        //             result.push_back(0);
        //         }
        //     }
        // // there is no 0's in nums            
        // } else {
        //     for (int num: nums) {
        //         result.push_back(product / num);
        //     }
        // }
        // return result;

        // prefix & postfix approach
        // time: O(n), space: O(n)
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> postfix(n, 1);
        vector<int> output(n, 0);
        
        // declare without initialization will can cause prod to have some garbage value
        long long prod = 1;
        // generate prefix array
        for (int i = 1; i < n; i++) {
            prod *= nums[i-1];
            prefix[i] = prod;
        }        
        prod = 1; // reset prod
        // generate postfix array
        for (int i = n - 2; i >= 0; i--) {
            prod *= nums[i+1];
            cout << prod << endl;
            postfix[i] = prod;
        }
        // generate output based on prefix * postfix for each index element
        for (int i = 0; i < n; i++) {
            output[i] = prefix[i] * postfix[i];
        }

        return output;
    }
};
