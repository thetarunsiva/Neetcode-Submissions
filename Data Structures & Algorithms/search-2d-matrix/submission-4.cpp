class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int outl = 0, outr = m.size() * m[0].size() - 1;
        while (outl <= outr) {
            int outmid = outl + (outr - outl)/2;
            int row = outmid/m[0].size();
            int col = outmid%m[0].size();
            if (m[row][col] == target) return true;
            else if (m[row][col] < target) outl = outmid + 1;
            else outr = outmid - 1;
        }
        return false;
    }
};
