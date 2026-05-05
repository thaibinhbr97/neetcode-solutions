class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        // // sorting
        // // time: O(nlogn)
        // // space: O(n)
        // if (nums.size() == 0) {
        //     return 0;
        // }
        // unordered_set<int> distinctNums;
        // for (int num : nums) {
        //     distinctNums.insert(num);
        // }
        // vector<int> elements;
        // for (int e : distinctNums) {
        //     elements.push_back(e);
        // }
        // sort(elements.begin(), elements.end());
        // int maxSoFar = 1; // longest consecutive sequence count
        // int result = maxSoFar;
        // for (int i = 1; i < elements.size(); i++) {
        //     if (elements[i] - elements[i-1] == 1) {
        //         maxSoFar++;
        //     } else {
        //         maxSoFar = 1;
        //     }
        //     result = max(result, maxSoFar);
        // }
        // return result;    

        // // using unordered_set without sorting to find the next element i+1,i+2,...
        // // in the hash table and keep track of the max so far in the longest consutive
        // // sequence of numbers, that number is not in the set meaning it will
        // // start the new sequence, we can reset the maxSoFar to be 1 (starting thew
        // // new consecutive sequence)
        // unordered_set<int> distincts;
        // for (int num: nums) {
        //     distincts.insert(num);
        // }
        // int maxSoFar = 0;
        // int result = 0;
        // for (int e: distincts) {
        //     maxSoFar = 1;
        //     while (distincts.contains(e+1)) {
        //         maxSoFar++;
        //         e++;
        //     }
        //     result = max(result, maxSoFar);
        // }
        // return result;

        // using unordered_set without sorting to find the next element i+1,i+2,...
        // in the hash table and keep track of the max so far in the longest consutive
        // sequence of numbers, that number is not in the set meaning it will
        // start the new sequence, we can reset the maxSoFar to be 1 (starting thew
        // new consecutive sequence)
        unordered_set<int> distincts;
        for (int num: nums) {
            distincts.insert(num);
        }
        int maxSoFar = 0;
        int result = 0;
        for (int e: distincts) {
            if (distincts.contains(e-1)) {
                continue;
            }
            maxSoFar = 1;
            while (distincts.contains(e+1)) {
                maxSoFar++;
                e++;
            }
            result = max(result, maxSoFar);
        }
        return result;        
    }    
};