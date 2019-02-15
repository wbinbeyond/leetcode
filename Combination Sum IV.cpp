/*class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int res = 0;
        sort(nums.begin(), nums.end());
        dfs(nums, target, res);
        return res;
    }
    void dfs(vector<int>& nums, int target,
             int& res) {
        if (target == 0) {
            res++;
            return;
        }
        if (target < 0) return;
        vector<bool> used(nums.size(), false);  //at the same recursion level, don't use same number again
        for (int i = 0; i < nums.size(); ++i) { // i = 0, at different level, can use same number again and again
            if (used[i]) continue;
            if (nums[i] > target) break;
            used[i] = true;
            dfs(nums, target - nums[i], res);
            used[i] = false;
        }
    }
};
*/

//Line 34: Char 35: runtime error: signed integer overflow
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto a : nums) {
                if (i >= a) dp[i] += dp[i - a];
            }
        }
        return dp.back();
    }
};
