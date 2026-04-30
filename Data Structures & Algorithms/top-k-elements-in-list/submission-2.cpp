class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // // time: O(nlogn)
        // // space: O(n)
        // unordered_map<int, int> counts;
        // for (int num: nums) {
        //     counts[num]++;
        // }
        // vector<pair<int,int>> freqPairs;
        // for (const auto& [num, freq]: counts) {
        //     // pairs.push_back(make_pair(freq, num));
        //     freqPairs.push_back({freq, num});
        // }
        // // sort by first index in pairs
        // sort(freqPairs.begin(), freqPairs.end(), [](const auto& a, const auto& b) {
        //     return a.first > b.first;
        // });
        // vector<int> result;
        // for (int i = 0; i < k; i++) {
        //     result.push_back(freqPairs[i].second);
        // }
        // return result;

        // bucket sort 
        // time: O(n)
        // space: O(n)
        unordered_map<int, int> counts;
        for (int num: nums) {
            counts[num]++;
        }
        // append num into their "count" bucket
        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& [num, count]: counts) {
            buckets[count].push_back(num);
        }
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int num: buckets[i]) {
                if (k == 0) {
                    return result;
                }
                result.push_back(num);
                k--;
            }
        }
        return result;
    }
};
