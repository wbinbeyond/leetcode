class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        for (int i = 0; i <= nums.size(); ++i) {
            dfs(nums, i, 0, cur, res);
        }
        return res;
    }
    void dfs(const vector<int>& nums, int n, int s,
             vector<int>& cur, vector<vector<int>>& res) {
        if (n == cur.size()) {
            res.push_back(cur); //push_back is making a copy of cur
            return;
        }
        for (int i = s; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(nums, n, i + 1, cur, res);
            cur.pop_back();
        }
    }
};
