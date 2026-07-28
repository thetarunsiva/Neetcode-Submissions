class Solution {
public:
    int onebits(int n) {
        int cc = 0;
        while (n > 0) {
            n = n & (n-1);
            cc++;
        }
        return cc;
    }
    vector<int> countBits(int n) {
        vector<int> a(n+1, 0);
        for (int i = 0; i <= n; i++) {
            a[i] = onebits(i);
        }
        return a;
    }
};
