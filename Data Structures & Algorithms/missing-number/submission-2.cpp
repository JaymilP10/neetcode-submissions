class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bool isMissing = false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                isMissing = true;
                return i;
            } else {
                isMissing = false;
            }
        }
        if (isMissing == false) {
            return nums.size();
        } else {
            return 0;
        }
    }
};
