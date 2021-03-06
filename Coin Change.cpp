class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, INT_MAX);
        memo[0] = 0;
        return helper(coins, amount, memo);
    }
    
    int helper(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount < 0) return -1;
        if (memo[amount] != INT_MAX) return memo[amount];
        int minCount = INT_MAX;
        for (int i = 0; i < coins.size(); ++i) {
            int tmp = helper(coins, amount - coins[i], memo);
            if (tmp >= 0) {
                minCount = min(minCount, tmp + 1);
            }
        }
        memo[amount] = (minCount == INT_MAX) ? -1 : minCount;
        return memo[amount];
    }
};


class Solution {
public: 
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, amount + 1);
        memo[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) 
                    memo[i] = min(memo[i], memo[i-coins[j]] + 1);
            }
        }
        return memo[amount] > amount ? -1 : memo[amount];
    }
};
