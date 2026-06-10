class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int i = 0, j = a.size() - 1;
        while (i < j) {
            if (a[i] + a[j] > target) {
                j--;
                continue;
            }
            else if (a[i] + a[j] < target) {
                i++;
                continue;
            }
            else {
                return {i+1, j+1};
            }
        }
    }
};
