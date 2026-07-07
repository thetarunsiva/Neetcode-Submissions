class Solution {
public:
    int ss = 0;
    vector<int> num;
    vector<vector<int>> ans;
    void back(vector<int> arr, int cc) {
        if (ss == cc) {
            ans.push_back(arr);
            return;
        }
        arr.push_back(num[cc]);
        back(arr, cc+1);
        arr.pop_back();
        back(arr, cc+1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ss = nums.size();
        num = nums;
        back({}, 0);
        return ans;
    }
};
