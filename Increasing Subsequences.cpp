class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        for (int i = 2; i <= nums.size(); ++i) {
            dfs(nums, i, 0, res, cur);
        }
        return res;
    }
    void dfs(vector<int>& nums, int n, int s,
            vector<vector<int>>& res,
            vector<int>& cur) {
        if (n == cur.size()) {
            res.push_back(cur);
            return;
        }
        unordered_set<int> seen;
        for (int i = s; i < nums.size(); ++i) {
            if (!cur.empty() && nums[i] < cur.back()) continue;
            if (seen.count(nums[i])) continue;
            cur.push_back(nums[i]);
            seen.insert(nums[i]);
            dfs(nums, n, i+1, res, cur);
            cur.pop_back();
        }
    }
};
