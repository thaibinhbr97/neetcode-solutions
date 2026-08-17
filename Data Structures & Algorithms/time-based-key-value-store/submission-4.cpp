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
        const vector<pair<int, string>>& values = store[key];
        int left = 0;
        int right = values.size() - 1;
        string res = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp) {
                res = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};
