class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT32_MAX;
        if (dividend == INT32_MIN) {
            if (divisor == -1) return INT32_MAX;
            else if (divisor == 1) return INT32_MIN;
        }
        long long divd = (long long) dividend;
        long long divs = (long long) divisor;
        int sign = 1;
        if (divd < 0) {
            divd = -divd;
            sign = -sign;
        }
        if (divs < 0) {
            divs = -divs;
            sign = -sign;
        }
        int res = 0;
        while (divd >= divs) {
            int shift = 1;
            while (divd >= (divs << shift)) {
                shift++;
            }
            divd -= divs << (shift - 1);
            res += 1 << (shift - 1);
        }
        return res * sign;
    }
};
