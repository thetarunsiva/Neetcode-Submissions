class Solution {
public:
    int robbery(int l, int r, vector<int>& v) {
        int n = r-l+1;
        vector<int> dp(n);
        dp[0] = v[l];
        dp[1] = max(dp[0], v[l+1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], v[l+i] + dp[i-2]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        if (nums.size() <= 3) {
            int ans = *max_element(nums.begin(), nums.end());
            return ans;
        }
        int n = nums.size();
        int take1 = robbery(0, n-2, nums);
        int not1 = robbery(1, n-1, nums);
        return max(take1, not1);
    }
};
