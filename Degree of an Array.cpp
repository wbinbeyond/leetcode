class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(),
            res = INT_MAX,
            degree = 0;
        unordered_map<int, int> m;
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < n; ++i)
        {
            if(m[nums[i]] == 0)
            {
                pos[nums[i]] = {i, i};
            }
            else
            {
                pos[nums[i]].second = i;
            }
            m[nums[i]]++;
            degree = max(degree, m[nums[i]]);
        }
        for (auto p : m)
        {
            if (degree == p.second)
            {
                res = min(res, pos[p.first].second  - pos[p.first].first + 1);
            }
        }
        return res;
    }
};
