class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int res = nums[0];
        vector<int> maxP(n, 0);
        vector<int> minP(n, 0);
        maxP[0] = minP[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            maxP[i] = max(max(maxP[i-1]*nums[i], minP[i-1]*nums[i]), nums[i]);
            minP[i] = min(min(maxP[i-1]*nums[i], minP[i-1]*nums[i]), nums[i]);
            res = max(res, maxP[i]);
        }
        return res;
    }
};
