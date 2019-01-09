// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my nuhttps://github.com/wbinbeyond/leetcodember is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 0,
            r = n;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int g = guess(m);
            if (g == 0) {
                return m;
            }
            else if (g == 1) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return -1;
    }
};
