class Solution {
public:
    int mySqrt(int x) {
        if (x == 1 || x == 0) return x;
        long start = 0,
            end = x;
        while (start + 1 < end) {
            // find last number satisfy square <= x
            long mid = (end - start) / 2 + start;
            if (mid * mid <= x) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (end * end <= x) return end;
        if (start * start <= x) return start;
        return -1;
    }
};
