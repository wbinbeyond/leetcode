class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(nums, 0, tmp, res);
        return res;
    }
    void backtrack(vector<int>& nums, int start, vector<int>& tmp, vector<vector<int>>& res) {
        res.push_back(tmp);
        for (int i = start; i < nums.size(); ++i) {
            // recording all subsets which include nums[i];
            tmp.push_back(nums[i]);
            backtrack(nums, i + 1, tmp, res);
            // remove nums[i] from current subset, and move forward to subsets don't contain nums[i]
            tmp.pop_back();
        }
    }
};
