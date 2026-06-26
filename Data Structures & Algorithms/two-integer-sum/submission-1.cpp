class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> answers;
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums.size(); j++){
                if (nums[i] + nums[j] == target && i != j){
                    answers.push_back(i);
                    answers.push_back(j);
                    return answers;
                }
            }
        }
    }
};
