/**

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0,
            right = nums.size(); // this needs to be n, not n - 1
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > mid) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        if (nums[left] > left) return left;
        return right;
    }
};
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            res ^= i ^ nums[i];
        }
        res ^= n;
        return res;
    }
};
