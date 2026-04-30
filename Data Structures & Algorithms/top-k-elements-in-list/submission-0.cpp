class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, pair<int,int>> mp;
        for (const int& num: nums) {
            if (mp.contains(num)) {
                mp[num].first++;
            } else {
                mp[num] = make_pair(1, num);
            }
        }
        vector<int> result;
        vector<pair<int,int>> pairs;
        for (const auto& [key, value]: mp) {
            pairs.push_back(value);
        }
        // sort by first index in pairs
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        for (size_t i = 0; i < k; i++) {
            result.push_back(pairs[i].second);
        }
        return result;
    }
};
