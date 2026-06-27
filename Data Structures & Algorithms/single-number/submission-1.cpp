class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> duplicates;

        for (int x : nums) {
            if (duplicates.find(x) == duplicates.end()) {
                duplicates.insert(x);
            } else {
                duplicates.erase(x);
            }
        }

        return *duplicates.begin();
    }
};
