class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i < n; ++i)
        {
            if (!isPrime[i]) continue;
            for (int j = i * 2; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime[i]) count++;
        }
        return count;
    }
};
