class Solution {
public:
    vector<int> main;
    vector<vector<int>> a;
    void back(vector<int> arr, int i) {
        a.push_back(arr);
        for (int j = i; j < main.size(); j++) {
            if (j > i && main[j] == main[j-1]) {
                continue;
            }
            arr.push_back(main[j]);
            back(arr, j+1);
            arr.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        main = nums;
        sort(main.begin(), main.end());
        back({}, 0);
        return a;
    }
};
