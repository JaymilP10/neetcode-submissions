class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        double size = nums1.size();
        double one = nums1[size/2 - 1];
        double two = nums1[size/2];
        if (nums1.size() % 2 == 1) {
            return nums1[size/2];
        } else {
            return (one + two) / 2;
        }
    }
};
