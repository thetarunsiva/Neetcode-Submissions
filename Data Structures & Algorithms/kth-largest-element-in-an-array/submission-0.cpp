class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        while (pq.size() < k) {
            int val = nums[i];
            pq.push(val);
            i++;
        }
        for (int j = i; j < nums.size(); j++) {
            int val = nums[j];
            if (val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};
