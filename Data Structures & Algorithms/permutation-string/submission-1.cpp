class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> a1(26, 0), a2(26, 0);
        if (s2.size() < s1.size()) {
            return false;
        }
        for (char i : s1) {
            int curr = i - 'a';
            a1[curr]++;
        }
        int l = 0;
        for (int r = 0; r < s2.size(); r++) {
            int curr = s2[r] - 'a';
            a2[curr]++;
            if (r - l + 1 > s1.size()) {
                int ncurr = s2[l] - 'a';
                a2[ncurr]--;
                l++;
            }
            if (a1 == a2) {
                return true;
            }
        }
        return false;
    }
};
