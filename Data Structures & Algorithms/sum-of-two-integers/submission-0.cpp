class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        int carry = b;
        while (carry != 0) {
            int tt = (sum & carry) << 1;
            sum = sum ^ carry;
            carry = tt;
        }
        return sum;
    }
};
