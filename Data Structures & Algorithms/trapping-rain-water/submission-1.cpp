class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        int l = 0;
        int r = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                leftMax = max(leftMax, height[l]);
                area += max(0, leftMax - height[l]);
                l++;
            } else {
                rightMax = max(rightMax, height[r]);
                area += max(0, rightMax - height[r]);
                r--;
            }
        }

        return area;
    }
};
