class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int outl = 0, outr = m.size() - 1;
        while (outl <= outr) {
            int outmid = outl + (outr - outl)/2;
            int inl = 0, inr = m[outmid].size() - 1;
            while (inl <= inr) {
                int inmid = inl + (inr - inl)/2;
                if (m[outmid][inmid] == target) return true;
                else if (m[outmid][inmid] < target) inl = inmid + 1;
                else inr = inmid - 1;
            }
            if (m[outmid][0] == target) return true;
            else if (m[outmid][0] < target) outl = outmid + 1;
            else outr = outmid - 1;
        }
        return false;
    }
};
