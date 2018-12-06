class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int res = 0,
            minPrice = prices[0],
            maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            else {
                maxProfit = max(prices[i] - minPrice, maxProfit);
            }
        }
        return maxProfit;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<int> dif(prices.size(), 0);
        for (int i = 1; i < prices.size(); ++i) {
            dif[i] = prices[i] - prices[i-1];
        }
        vector<int> dp(dif.size(), 0);
        int maxSum = 0;
        for (int j = 1; j < dif.size(); ++j) {
            dp[j] = max(dif[j], dif[j] + dp[j-1]);
            if (dp[j] > maxSum) {
                maxSum = dp[j];
            }
        }
        return maxSum;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<int> dif(prices.size(), 0);
        for (int i = 1; i < prices.size(); ++i) {
            dif[i] = prices[i] - prices[i-1];
        }
        
        int curSum = 0;
        int maxSum = 0;
        for (int j = 0; j < dif.size(); ++j) {
            curSum += dif[j];
            if (curSum > maxSum) {
                maxSum = curSum;
            }
            if (curSum < 0) {
                curSum = 0;
            }
        }
        return maxSum;
    }
};
