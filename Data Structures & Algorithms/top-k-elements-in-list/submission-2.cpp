class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        vector<vector<int>> ff(nums.size() + 1);
        for (auto &i : mpp) {
            ff[i.second].push_back(i.first);
        }
        vector<int> a;
        for (int i = nums.size(); i >= 0; i--) {
            if (k == 0) {
                return a;
            }
            if (ff[i].size() > 0) {
                a.push_back(ff[i].back());
                ff[i].pop_back();
                i++;
                k--;
            }
        }
        return a;
    }
};
