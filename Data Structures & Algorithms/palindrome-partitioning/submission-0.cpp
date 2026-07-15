class Solution {
public:
    vector<vector<string>> a;
    vector<string> curr;
    string ss;
    bool isPal(int start, int end) {
        while (start < end) {
            if (ss[start] != ss[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void back(int i) {
        if (i == ss.size()) {
            a.push_back(curr);
            return;
        }
        for (int end = i; end < ss.size(); end++) {
            if (isPal(i, end)) {
                string tt = ss.substr(i, end - i + 1);
                curr.push_back(tt);
                back(end+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ss = s;
        back(0);
        return a;
    }
};
