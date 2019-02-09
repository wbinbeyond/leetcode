class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        // make res = 0, this handles empty nums case; res = 1, is not right
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
