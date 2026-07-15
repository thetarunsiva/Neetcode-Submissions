class Solution {
public:
    vector<int> main;
    set<vector<int>> a;
    void back(vector<int> arr, vector<bool> fill, int i) {
        if (i == main.size()) {
            sort(arr.begin(), arr.end());
            a.insert(arr);
        }
        for (int j = 0; j < main.size(); j++) {
            if (!fill[j]) {
                arr.push_back(main[j]);
                fill[j] = true;
                back(arr, fill, i+1);
                arr.pop_back();
                back(arr, fill, i+1);
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        main = nums;
        vector<bool> fill(main.size(), false);
        back({}, fill, 0);
        vector<vector<int>> ans;
        for (vector<int> i : a) {
            ans.push_back(i);
        }
        return ans;
    }
};
