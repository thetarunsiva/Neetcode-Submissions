class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        vector<int> a;
        int n = nums.size();
        int i = 0;
        int ma = 0;
        for (int j = 0; j < n; j++) {
            ma = max(ma, nums[j]);
            if (j - i + 1 == k) {
                a.push_back(ma);
                if (nums[i] == ma) {
                    ma = 0;
                    for (int k = i+1; k <= j; k++) ma = max(ma, nums[k]);
                }
                i++;
            }
        }
        return a;
    }
};
