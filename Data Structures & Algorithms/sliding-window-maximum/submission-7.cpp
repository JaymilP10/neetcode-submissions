class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        int max = INT_MIN;
        int l = 0, r = 0;

        if (nums.size() == 1) {
            output.push_back(nums[0]);
            return output;
        }

        if (nums.size() == 0) {
            return output;
        }

        while (r < nums.size()) {
            
            if (nums[r] >= max) {
                max = nums[r];
            }

            if ((r - l + 1) == k) {
                l++;
                r = l - 1;
                output.push_back(max);
                max = INT_MIN;
                cout << "l: " << l << " r: " << r << " max: " << max << "\n";
            }

            r++;
        }
        return output;
    }
};
