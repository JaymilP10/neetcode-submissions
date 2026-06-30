class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 0) {
            return 0;
        }
        vector<int> x = nums;
        x.pop_back();
        vector<int> case1 = x;
        nums.erase(nums.begin());
        vector<int> case2 = nums;
        return max(returnMax(case1), returnMax(case2));
    }

    int returnMax(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 0) {
            return 0;
        }
        int m = 0;
        int x = nums[0];
        int y = max(nums[1], x);

        for (int i = 2; i < nums.size(); i++) {
            m = max(y, x + nums[i]);
            x = y;
            y = m;
        }

        return max(x, y);
    }
};
