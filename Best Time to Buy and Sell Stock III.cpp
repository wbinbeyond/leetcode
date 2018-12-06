class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> left(n, 0);
        int leftMaxProfit = 0,
            leftMinPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            if (prices[i] < leftMinPrice) {
                leftMinPrice = prices[i];
            }
            else {
                leftMaxProfit = max(leftMaxProfit, prices[i] - leftMinPrice);
            }
            left[i] = leftMaxProfit;
        }
        
        int rightMaxProfit = 0,
            rightMaxPrice = prices[n-1],
            res = left[n-1];
        for (int i = n - 2; i >= 0; --i) {
            if (prices[i] > rightMaxPrice) {
                rightMaxPrice = prices[i];
            }
            else {
                rightMaxProfit = max(rightMaxProfit, rightMaxPrice - prices[i]);
            }
            res = max(res, rightMaxProfit + left[i]);
        }
        return res;
    }
};
