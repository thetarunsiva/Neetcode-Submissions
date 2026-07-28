class Solution {
public:
    int reverse(int x) {
        int z = 0;
        while (x != 0) {
            int unit = x%10;
            if (z > INT_MAX / 10 or z < INT_MIN / 10) {
                return 0;
            }
            z = z * 10 + unit;
            x /= 10;
        }
        return z;
    }
};
