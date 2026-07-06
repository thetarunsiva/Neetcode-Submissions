class MedianFinder {
public:
    vector<int> v;
    int mid = 0;
    int ee = 1;
    MedianFinder() {
        
    }
    void addNum(int num) {
        v.push_back(num);
        sort(v.begin(), v.end());
        if (v.size()%2 == 0) {
            ee = 1;
        }
        else {
            ee = 0;
        }
        mid = v.size() / 2;
    }
    
    double findMedian() {
        if (ee) {
            double ans = (v[mid] + v[mid-1]) / 2.0;
            return ans;
        }
        else {
            double ans = v[mid] / 1.0;
            return ans;
        }
    }
};
