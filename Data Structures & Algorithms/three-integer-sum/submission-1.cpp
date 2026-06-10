class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& t) {
        vector<vector<int>> a;
        sort(t.begin(), t.end());
        for (int i = 0; i < t.size(); i++) {
            if (i > 0 && t[i] == t[i-1]) {
                continue;
            }
            int target = t[i];
            int j = i+1;
            int k = t.size()-1;
            while (j < k) {
                if (t[j] + t[k] > -(target)) {
                    k--;
                }
                else if (t[k] + t[j] < -(target)) {
                    j++;
                }
                else {
                    a.push_back({t[i], t[j], t[k]});
                    j++; k--;
                    while (j < k && t[j] == t[j-1]) {
                        j++;
                    }
                    while (j < k && t[k] == t[k+1]) {
                        k--;
                    }
                }
            }
        }
        return a;
    }
};
