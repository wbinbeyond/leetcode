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
