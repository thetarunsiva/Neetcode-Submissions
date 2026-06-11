class Solution {
public:
    bool test(vector<int>& a1, vector<int>& a2) {
        bool ff = true;
        for (int k = 0; k < 52; k++) {
            if (a1[k] && a2[k] < a1[k]) {
                ff = false;
                break;
            }
        }
        return ff;
    }
    string minWindow(string s, string t) {
        vector<int> a1(52, 0), a2(52, 0);
        if (s.size() < t.size()) {
            return "";
        }
        for (char i : t) {
            if (isupper(i)) {
                int curr = i - 'A';
                a1[curr]++;
            }
            else {
                int curr = i - 'a' + 26;
                a1[curr]++;
            }
        }
        int i = 0;
        string ss = "";
        bool anythingFound = false;
        for (int j = 0; j < s.size(); j++) {
            if (isupper(s[j])) {
                int curr = s[j] - 'A';
                a2[curr]++;
            }
            else {
                int curr = s[j] - 'a' + 26;
                a2[curr]++;
            }
            bool ff = test(a1, a2);
            if (ff) {
                
                while (test(a1, a2)) {
                    int curr;
                    if (isupper(s[i])) {
                        curr = s[i] - 'A';
                        a2[curr]--;
                    }
                    else {
                        int curr = s[i] - 'a' + 26;
                        a2[curr]--;
                    }
                    i++;
                }
                string nss = s.substr(i-1, (j-i+2));
                if (anythingFound == false) {
                    ss = nss;
                    anythingFound = true;
                }
                if (nss.size() < ss.size()) {
                    ss = nss;
                }
            }
        }
        return ss;
    }
};
