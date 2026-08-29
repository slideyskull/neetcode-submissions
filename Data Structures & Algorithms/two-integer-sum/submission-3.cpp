class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            if (!m.contains(target - nums[i])) {
                m[target - nums[i]] = i;
            }
            if (m.contains(nums[i]) && m[nums[i]] != i) {
                return vector<int>{m[nums[i]], i};
            }
        }

        return {0, 0};
    }
};
