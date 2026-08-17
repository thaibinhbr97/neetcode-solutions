class TimeMap {
private:
    // key -> vector of {timestamp, value}
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // if key does not exist in store, return early ""
        if (store.find(key) == store.end()) {
            return "";
        }
        int left = 0;
        int right = store[key].size() - 1;
        string res = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (store[key][mid].first <= timestamp) {
                res = store[key][mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};
