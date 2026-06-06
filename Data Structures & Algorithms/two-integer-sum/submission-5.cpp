class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int bal = target - nums[i];
            if (mpp.find(bal) != mpp.end()) {
                return {mpp[bal], i};
            }
            else {
                mpp[nums[i]] = i; 
            }
        }

    }
};