class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = (right - left) / 2 + left;
            int count = countNums(nums, mid);
            if (count <= mid) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        if (countNums(nums, left) > left) return left;
        return right;
    }
    
    int countNums(vector<int>& nums, int num) {
        int count = 0;
        for (auto& n : nums) {
            if (n <= num) count++;
        }
        return count;
    }
};
