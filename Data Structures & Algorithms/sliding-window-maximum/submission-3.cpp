class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        vector<int> a;
        int n = nums.size();
        int i = 0;
        priority_queue<pair<int, int>> pq;
        for (int j = 0; j < n; j++) {
            pq.push({nums[j], j});
            if (j - i + 1 == k) {
                while (!pq.empty() && pq.top().second < i) {
                    pq.pop();
                }
                int ma = pq.top().first;
                a.push_back(ma);
                i++;
            }
        }
        return a;
    }
};
