class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // // time: O(n^3)
        // // space: O(k), k is a number of unique triplets
        // vector<vector<int>> triplets;
        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < nums.size(); i++) {
        //     if (i > 0 && nums[i] == nums[i - 1]) continue;
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (j > i + 1 && nums[j] == nums[j-1]) continue;
        //         for (int k = j + 1; k < nums.size(); k++) {
        //             if (k > j + 1 && nums[k] == nums[k-1]) continue;
        //             if (nums[i] + nums[j] + nums[k] == 0) {
        //                 triplets.push_back({nums[i], nums[j], nums[k]});
        //             }
        //         }
        //     }
        // }
        // return triplets;

        // // time: O(n^3)
        // // space: O(k), k is a number of unique triplets
        // set<vector<int>> triplets;
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         for (int k = j + 1; k < nums.size(); k++) {
        //             if (nums[i] + nums[j] + nums[k] == 0) {
        //                 vector<int> temp = {nums[i], nums[j], nums[k]};
        //                 sort(temp.begin(), temp.end());
        //                 triplets.insert(temp);
        //             }
        //         }
        //     }
        // }
        // return vector<vector<int>>(triplets.begin(), triplets.end());  

        // time: O(n^2)
        // space: O(k), # of distinct triplets
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                if (total == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j-1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k+1]) {
                        k--;
                    }
                } else if (total > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
};
