class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, res);
        return res;
    }
    void dfs (vector<int>& candidates, int target, int s,
              vector<int>& cur,
              vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = s; i < candidates.size(); ++i) {
            if (candidates[i] > target) continue;
            if ( i > s && candidates[i] == candidates[i -1]) continue;
            cur.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, cur, res);
            cur.pop_back();
        }
    }
};
