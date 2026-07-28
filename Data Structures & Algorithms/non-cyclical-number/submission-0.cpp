class Solution {
public:
    int sum(int n) {
        int cc = 0;
        while (n) {
            cc += (n%10)*(n%10);
            n /= 10;
        }
        return cc;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        while (true) {
            int curr = sum(n);
            if (curr == 1) {
                return true;
            }
            if (s.contains(curr)) {
                return false;
            }
            s.insert(curr);
            n = curr;
        }
    }
};
