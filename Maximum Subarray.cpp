class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = nums[0];
        int n = nums.size();
        vector<int> maxD(n, 0);
        maxD[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            maxD[i] = max(maxD[i-1] + nums[i], nums[i]);
            res = max(res, maxD[i]);
        }
        return res;
    }
};
