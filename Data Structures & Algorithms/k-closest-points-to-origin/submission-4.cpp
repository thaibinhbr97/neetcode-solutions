using HeapNode = pair<int, vector<int>>;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> minHeap;
        for (vector<int> point: points) {
            int distaneSquare = point[0] * point[0] + point[1] * point[1];
            HeapNode p = {distaneSquare, point};
            minHeap.push(p);
        }
        vector<vector<int>> result;
        while (!minHeap.empty() && k > 0) {
            vector<int> point = minHeap.top().second;
            minHeap.pop();
            result.push_back(point);
            k--;
        }
        return result;
    }
};
