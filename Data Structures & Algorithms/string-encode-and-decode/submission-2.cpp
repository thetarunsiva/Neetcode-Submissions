class Solution {
   public:
    string encode(vector<string>& strs) {
        string s = "";
        for (string i : strs) {
            s += to_string(i.size()) + "@" + i;
        }
        cout << s << " ";
        return s;
    }
    vector<string> decode(string s) {
        vector<string> a;
        int len = 0;
        string lens = "";
        for (int i = 0; i < s.size(); i++) {
            char curr = s[i];
            if (curr <= '9' and curr >= '0') {
                lens += curr;
                continue;
            }
            else if (curr = '@') {
                len = stoi(lens);
                string ss = s.substr(i+1, len);
                a.push_back(ss);
                i += len;
                len = 0;
                lens = "";
            }
        }
        return a;
    }
};
