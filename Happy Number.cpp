class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1)
        {
            int t = 0;
            while (n != 0)
            {
                t += (n % 10) * (n % 10);
                n /= 10;
            }
            n = t;
            if (s.count(n) != 0)
            {
                break;
            }
            else
            {
                s.insert(n);
            }
        }
        return n == 1;
    }
};
