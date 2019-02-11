class Solution {
private:
    vector<vector<int>> subsets;
    vector<int> subset;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return subsets;
    }
    void backtrack(vector<int>& nums, int start) {
        subsets.push_back(subset);
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i-1])
                continue;
            subset.push_back(nums[i]);
            backtrack(nums, i + 1);
            subset.pop_back();
        }
    }
};
