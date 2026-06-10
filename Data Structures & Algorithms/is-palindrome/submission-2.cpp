class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            if ((tolower(s[i]) > '9' or tolower(s[i]) < '0') and (tolower(s[i]) > 'z' or tolower(s[i]) < 'a')) {
                i++;
                continue;
            }
            if ((tolower(s[j]) > '9' or tolower(s[j]) < '0') and (tolower(s[j]) > 'z' or tolower(s[j]) < 'a')) {
                j--;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            else {
                i++;
                j--;
            }
        }
        return true;
    }
};
