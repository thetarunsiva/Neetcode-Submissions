class Solution {
   public:
    vector<int> main;
    vector<vector<int>> a;
    void back(vector<int> arr, vector<bool> fill, int i) {
        if (i == main.size()) {
            a.push_back(arr);
            return;
        }
        for (int j = 0; j < fill.size(); j++) {
            if (fill[j] == false) {
                arr.push_back(main[j]);
                fill[j] = true;
                back(arr, fill, i + 1);
                fill[j] = false;
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        main = nums;
        vector<bool> fill(nums.size(), false);
        back({}, fill, 0);
        vector<vector<int>> ans = a;
        return ans;
    }
};