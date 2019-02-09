class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int comp = target - nums[i];
            if (hash.find(comp) != hash.end()) {
                res.push_back(hash[comp]);
                res.push_back(i);
            }
            else {
                hash[nums[i]] = i;
            }
        }
        return res;
    }
};
