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
        memo[amount] = minCount;
        return memo[amount] == INT_MAX ? -1 : memo[amount];
    }
};
