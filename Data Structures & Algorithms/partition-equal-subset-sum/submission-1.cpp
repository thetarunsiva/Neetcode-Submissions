class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s%2) return false;
        int tt = s/2;
        vector<bool> dp(tt+1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int i = tt; i >= num; i--) {
                if (dp[i-num] == true) {
                    dp[i] = true;
                }
            }
        }
        return dp[tt];
    }
};