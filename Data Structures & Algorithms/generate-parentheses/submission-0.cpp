class Solution {
public:
    int total;
    vector<string> bb;
    void back(int open, int close, string s) {
        if (open == total && close == total) {
            bb.push_back(s);
            return;
        }
        if (open < total) {
            s += '(';
            back(open+1, close, s);
            s.pop_back();
        }
        if (open > close) {
            s += ')';
            back(open, close+1, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        total = n;
        back(0, 0, "");
        return bb;
    }
};
