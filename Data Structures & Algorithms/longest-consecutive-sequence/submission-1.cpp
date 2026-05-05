class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        unordered_set<int> distinctNums;
        for (int num : nums) {
            distinctNums.insert(num);
        }
        vector<int> elements;
        for (int e : distinctNums) {
            elements.push_back(e);
        }
        sort(elements.begin(), elements.end());
        int maxSoFar = 1; // longest consecutive sequence count
        int result = maxSoFar;
        for (int i = 1; i < elements.size(); i++) {
            if (elements[i] - elements[i-1] == 1) {
                maxSoFar++;
            } else {
                maxSoFar = 1;
            }
            result = max(result, maxSoFar);
        }
        return result;    
    }    
};