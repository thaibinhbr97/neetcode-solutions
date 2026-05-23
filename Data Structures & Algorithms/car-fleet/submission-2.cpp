class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // time: O(nlogn), space: O(n)
        int n = position.size();
        unordered_map<int, double> positionTime; // key: position, value: hours to target
        for (int i = 0; i < n; i++) {
            positionTime[position[i]] = (double) (target - position[i]) / speed[i];
        }
        sort(position.begin(), position.end(), greater<int>()); // sort in descending order by position
        stack<double> st;
        for (int i = 0; i < n; i++) {
            if (!st.empty() && positionTime[position[i]] <= st.top()) {
                continue;
            }
            st.push(positionTime[position[i]]);
        }
        return st.size();
    }
};
