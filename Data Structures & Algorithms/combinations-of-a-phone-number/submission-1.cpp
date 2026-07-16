class Solution {
public:
    string ss;
    vector<string> a;
    unordered_map<char, vector<char>> mpp = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    void back(int i, string s) {
        if (i == ss.size()) {
            a.push_back(s);
            return;
        }
        vector<char> v = mpp[ss[i]];
        for (char j : v) {
            s += j;
            back(i+1, s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        ss = digits;
        if (ss.empty()) return {};
        back(0, "");
        return a;
    }
};
