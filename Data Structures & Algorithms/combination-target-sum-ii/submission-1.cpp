class Solution {
public:
    int tar;
    vector<int> num;
    vector<vector<int>> ans;
    void back(vector<int> nums, int ind, int s) {
        if (s == tar) {
            ans.push_back(nums);
            return;
        }
        if (s > tar) {
            return;
        }
        for (int i = ind; i < num.size(); i++) {
            if (i > ind && num[i] == num[i-1]) {
                continue; // Skipping duplicates [1, 2, 2]..
            }
            s += num[i];
            nums.push_back(num[i]);
            back(nums, i+1, s);
            nums.pop_back();
            s -= num[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        tar = target;
        sort(candidates.begin(), candidates.end());
        num = candidates;
        back({}, 0, 0);
        return ans;
    }
};
