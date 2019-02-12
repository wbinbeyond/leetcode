class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
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
            if (i > s && nums[i] == nums[i-1])
                continue;
            cur.push_back(nums[i]);
            dfs(nums, n, i + 1, cur, res);
            cur.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
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
        unordered_set<int> seen; //same level only use once
        for (int i = s; i < nums.size(); ++i) {
            if (seen.count(nums[i])) continue;
            cur.push_back(nums[i]);
            seen.insert(nums[i]);
            dfs(nums, n, i + 1, cur, res);
            cur.pop_back();
        }
    }
};
