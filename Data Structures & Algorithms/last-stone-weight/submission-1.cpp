class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // time: O(nlogn)
        // space: O(n)
        priority_queue<int> maxHeap;
        for (int stone: stones) {
            maxHeap.push(stone);
        }
        while (maxHeap.size() > 1) {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if (x == y) {
                continue;
            } else if (x > y) {
                maxHeap.push(x - y);
            }
        }

        // if (maxHeap.size() == 1) {
        //     return maxHeap.top();
        // } else {
        //     return 0;
        // }
        maxHeap.push(0);
        return maxHeap.top();
    }
};
