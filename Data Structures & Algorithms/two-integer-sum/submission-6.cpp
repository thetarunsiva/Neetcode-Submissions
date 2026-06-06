class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int bal = target - nums[i];
            if (mpp.contains(bal)) {
                return {mpp[bal], i};
            }
            mpp[nums[i]] = i; 
        }
    }
};