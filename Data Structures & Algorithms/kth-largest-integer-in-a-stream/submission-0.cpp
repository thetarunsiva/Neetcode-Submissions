class KthLargest {
public:
    priority_queue<int> pq;
    int kk = 0;
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for (int i : nums) {
            pq.push(i);
        }
    }
    
    int add(int val) {
        pq.push(val);
        int k = kk;
        vector<int> temp;
        while (k != 1) {
            int i = pq.top();
            pq.pop();
            temp.push_back(i);
            k--;
        }
        int ans = pq.top();
        for (int i : temp) pq.push(i);
        return ans;
    }
};
