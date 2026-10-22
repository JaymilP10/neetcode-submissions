class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        vector<vector<int>> result;
        vector<int> current = {};

        backtrack(nums, target, 0, current, result);

        return result;
    }

    void backtrack(vector<int>& nums, int remain, int start, vector<int>& current, vector<vector<int>>& result) {
        if (remain == 0) {
            result.push_back(current);
            return;
        }

        if (remain < 0) {
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);

            backtrack(nums, remain - nums[i], i, current, result);

            current.pop_back();
        }

    }
};
