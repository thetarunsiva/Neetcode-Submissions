class Solution {
public:
    int m;
    vector<vector<string>> a;
    unordered_set<int> cols;
    unordered_set<int> d1;
    unordered_set<int> d2;
    void back(int r, vector<string>& curr) {
        if (r == m) {
            a.push_back(curr);
            return;
        }
        for (int i = 0; i < m; i++) {
            if (cols.contains(i) or d1.contains(r+i) or d2.contains(r-i)) {
                continue;
            }
            cols.insert(i);
            d1.insert(r+i);
            d2.insert(r-i);
            string s(m, '.');
            s[i] = 'Q';
            curr.push_back(s);
            back(r+1, curr);
            curr.pop_back();
            cols.erase(i);
            d1.erase(r+i);
            d2.erase(r-i);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        m = n;
        vector<string> curr;
        back(0, curr);
        return a;
    }
};
