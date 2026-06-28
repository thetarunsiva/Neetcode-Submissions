class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kk = 0;
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        if (nums.size() < k) {
            for (int i : nums) {
                pq.push(i);
            }
        }
        else {
            int i = 0;
            while (pq.size() < kk) {
                pq.push(nums[i]);
                i++;
            }
            while (i < nums.size()) {
                if (pq.top() < nums[i]) {
                    pq.pop();
                    pq.push(nums[i]);
                }
                i++;
            }
        }
    }
    int add(int val) {
        if (pq.size() < kk) {
            pq.push(val);
        }
        else if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};
