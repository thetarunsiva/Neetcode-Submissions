class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mpp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mpp.count(key) == 0) return "";
        auto& a = mpp[key];
        int l = 0;
        int r = a.size()-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (a[mid].first == timestamp) {
                return a[mid].second;
            }
            else if (a[mid].first < timestamp) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (r < 0) { // All timestamps are stricty greater than the needed timestamp
            return "";
        }
        return a[r].second;
    }
};
