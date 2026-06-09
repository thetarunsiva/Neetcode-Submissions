class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string r1 = "";
        for (char i : s) {
            if ((i <= '9' and i >= '0') or (i <= 'z' and i >= 'a')) {
                r1 += i;
            }
        }
        string r2 = r1;
        reverse(r2.begin(), r2.end());
        cout << r1 << " | " << r2;
        if (r1 == r2) return true;
        else return false;
    }
};
