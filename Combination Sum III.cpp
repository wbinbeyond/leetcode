class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(k, n, 1, cur, res);
        return res;
    }
    void dfs(int k, int target, int start, vector<int>& cur, vector<vector<int>>& res) {
        if (target == 0 && cur.size() == k) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i < 10; ++i) {
            if (i > target) break;
            cur.push_back(i);
            dfs(k, target - i, i + 1, cur, res);
            cur.pop_back();
        }
    }
};
