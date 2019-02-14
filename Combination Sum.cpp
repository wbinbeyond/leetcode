class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(candidates, target, 0, res, cur);
        return res;
    }
    
    void dfs(vector<int>& candidates, int target, int s,
             vector<vector<int>>& res,
             vector<int>& cur) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = s; i < candidates.size(); ++i) {
            if (candidates[i] > target) continue;
            cur.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, res, cur);
            cur.pop_back();
        } 
    }
};
