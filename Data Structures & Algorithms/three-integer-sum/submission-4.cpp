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

        set<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int j = 0;
            int k = n-1;
            while (j < k) {
                if (j == i) {
                    j++;
                    continue;
                }
                if (k == i) {
                    k--;
                    continue;
                }
                if (nums[j] + nums[k] == -nums[i]) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    result.insert(temp);
                    j++;
                    k--;
                } else if (nums[j] + nums[k] > -nums[i]) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};
